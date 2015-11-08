#!/usr/bin/env python

import numpy

dac_gen_i = '''/* Generated by dac.py. */

static float dac_gen_sine[128] = {{ {samples} }};
'''

number_of_samples = 128
sine_samples = []

for i in range(0, number_of_samples):
    x = i * 2 * numpy.pi / number_of_samples
    sine_samples.append(numpy.sin(x))

with open("dac_gen.i", "w") as f:
    samples = ', '.join(['%f' % sample for sample in sine_samples])
    f.write(dac_gen_i.format(samples=samples))