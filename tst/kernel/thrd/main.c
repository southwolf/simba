/**
 * @section License
 *
 * The MIT License (MIT)
 * 
 * Copyright (c) 2014-2016, Erik Moqvist
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * This file is part of the Simba project.
 */

#include "simba.h"

#if defined(ARCH_ESP32)
static THRD_STACK(suspend_resume_stack, 512);
#else
static THRD_STACK(suspend_resume_stack, 256);
#endif

static void *suspend_resume_main(void *arg_p)
{
    thrd_set_name("resumer");
    thrd_resume(arg_p, 3);

    return (NULL);
}

static int test_suspend_resume(struct harness_t *harness_p)
{
    int err;
    struct thrd_t *thrd_p;

    thrd_p = thrd_spawn(suspend_resume_main,
                        thrd_self(),
                        10,
                        suspend_resume_stack,
                        sizeof(suspend_resume_stack));

    err = thrd_suspend(NULL);
    BTASSERT(err == 3);

    /* Wait for the spawned thread to terminate, twice. */
    BTASSERT(thrd_join(thrd_p) == 0);
    BTASSERT(thrd_join(thrd_p) == 0);

    return (0);
}

static int test_yield(struct harness_t *harness_p)
{
    BTASSERT(thrd_yield() == 0);

    return (0);
}

static int test_sleep(struct harness_t *harness_p)
{
    BTASSERT(thrd_sleep(0.001) == 0);
    BTASSERT(thrd_sleep_ms(1) == 0);
    BTASSERT(thrd_sleep_us(1000) == 0);

    return (0);
}

static int test_priority(struct harness_t *harness_p)
{
    BTASSERT(thrd_get_prio() == 0);
    BTASSERT(thrd_set_prio(thrd_self(), 1) == 0);
    BTASSERT(thrd_get_prio() == 1);

    return (0);
}

static int test_log_mask(struct harness_t *harness_p)
{
    char command[64];

    BTASSERT(thrd_get_log_mask() == 0x0f);
    BTASSERT(thrd_set_log_mask(thrd_self(), 0x00) == 0x0f);
    BTASSERT(thrd_get_log_mask() == 0x00);

    strcpy(command, "/kernel/thrd/set_log_mask main 0xff");
    BTASSERT(fs_call(command, NULL, chan_null(), NULL) == 0);
    BTASSERT(thrd_get_log_mask() == 0xff);

    return (0);
}

#if CONFIG_PREEMPTIVE_SCHEDULER == 1

static THRD_STACK(preemptive_stack, 256);

static void *preemptive_main(void *arg_p)
{
    thrd_set_name("preemptive");

    while (1);

    return (NULL);
}

static int test_preemptive(struct harness_t *harness_p)
{
    struct time_t timeout;
    struct time_t start, stop, duration;

    /* Spawn a low priority worker thread. */
    BTASSERT(thrd_spawn(preemptive_main,
                        NULL,
                        20,
                        preemptive_stack,
                        sizeof(preemptive_stack)) != NULL);

    BTASSERT(time_get(&start) == 0);

    /* Suspend this thread to make sure the worker thread is in its
       infinite loop. When the suspend timeout occurs, this thread
       will be scheduled since it has higher priority than the worker
       thread. */
    timeout.seconds = 0;
    timeout.nanoseconds = 10000000;
    BTASSERT(thrd_suspend(&timeout) == -ETIMEDOUT);

    BTASSERT(time_get(&stop) == 0);
    BTASSERT(time_diff(&duration, &stop, &start) == 0);

    BTASSERT(duration.seconds == 0);
    BTASSERT(duration.nanoseconds == 10000000);

    return (0);
}

#else

static int test_preemptive(struct harness_t *harness_p)
{
    return (1);
}

#endif

static int test_env(struct harness_t *harness_p)
{
#if CONFIG_THRD_ENV == 1

    struct thrd_environment_variable_t global_variables[2];
    struct thrd_environment_variable_t variables[4];

    /* Default thread environment is setup correctly. */
    BTASSERT(thrd_get_env("FOO") == NULL);

    /* Set and get are not possible for a thread without an
       environment. */
    BTASSERT(thrd_init_env(NULL, 0) == 0);
    BTASSERT(thrd_set_env("CWD", "/") == -1);
    BTASSERT(thrd_get_env("CWD") == NULL);

    /* Initialize the global environment. */
    BTASSERT(thrd_init_global_env(global_variables,
                                  membersof(global_variables)) == 0);

    /* Set and get global variables. */
    BTASSERT(thrd_set_global_env("N1", "G1") == 0);
    BTASSERT(thrd_get_global_env("N1") != NULL);
    BTASSERT(strcmp(thrd_get_global_env("N1"), "G1") == 0);

    BTASSERT(thrd_set_global_env("N2", "G2") == 0);
    BTASSERT(thrd_get_global_env("N2") != NULL);
    BTASSERT(strcmp(thrd_get_env("N2"), "G2") == 0);

    /* Get from global environment using the thread local get
       function. */
    BTASSERT(thrd_get_env("N1") != NULL);
    BTASSERT(strcmp(thrd_get_env("N1"), "G1") == 0);

    /* Initialize the environment for the current thread. */
    BTASSERT(thrd_init_env(variables, membersof(variables)) == 0);

    /* Set and get variables. The global N1 is overridden. */
    BTASSERT(thrd_set_env("N1", "L1") == 0);
    BTASSERT(thrd_get_env("N1") != NULL);
    BTASSERT(strcmp(thrd_get_env("N1"), "L1") == 0);

    BTASSERT(thrd_set_env("N2", "L2") == 0);
    BTASSERT(thrd_get_env("N2") != NULL);
    BTASSERT(strcmp(thrd_get_env("N2"), "L2") == 0);

    BTASSERT(thrd_set_env("N3", "L3") == 0);
    BTASSERT(thrd_get_env("N3") != NULL);
    BTASSERT(strcmp(thrd_get_env("N3"), "L3") == 0);

    BTASSERT(thrd_set_env("N4", "L4") == 0);
    BTASSERT(thrd_get_env("N4") != NULL);
    BTASSERT(strcmp(thrd_get_env("N4"), "L4") == 0);

    /* Overwrite a value. */
    BTASSERT(thrd_set_env("N4", "L44") == 0);
    BTASSERT(thrd_get_env("N4") != NULL);
    BTASSERT(strcmp(thrd_get_env("N4"), "L44") == 0);

    /* No free space. */
    BTASSERT(thrd_set_env("N5", "L5") == -1);

    /* Remove a variable. */
    BTASSERT(thrd_set_env("N2", NULL) == 0);

    /* Set and get another variable. */
    BTASSERT(thrd_set_env("N6", "L6") == 0);
    BTASSERT(thrd_get_env("N6") != NULL);
    BTASSERT(strcmp(thrd_get_env("N6"), "L6") == 0);

    /* Get a non-existing variable. */
    BTASSERT(thrd_get_env("N7") == NULL);

    /* Remove the local environment. */
    BTASSERT(thrd_init_env(NULL, 0) == 0);

    /* Remove the global environment. */
    BTASSERT(thrd_init_global_env(NULL, 0) == 0);

    return (0);

#else

    return (1);

#endif
}

static int test_get_by_name(struct harness_t *harness_p)
{
    BTASSERT(thrd_get_by_name("main") == thrd_self());
    BTASSERT(thrd_get_by_name("none") == NULL);

    return (0);
}

int main()
{
    struct harness_t harness;
    struct harness_testcase_t harness_testcases[] = {
        { test_suspend_resume, "test_suspend_resume" },
        { test_yield, "test_yield" },
        { test_sleep, "test_sleep" },
        { test_priority, "test_priority" },
        { test_log_mask, "test_log_mask" },
        { test_preemptive, "test_preemptive" },
        { test_env, "test_env" },
        { test_get_by_name, "test_get_by_name" },
        { NULL, NULL }
    };

    sys_start();

    harness_init(&harness);
    harness_run(&harness, harness_testcases);

    return (0);
}
