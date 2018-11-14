import matplotlib
matplotlib.use("Agg")
import numpy as np
import matplotlib.pyplot as plt
import sys
n=500
mu=0
sigma=1

from scipy.stats import norm


d1=np.genfromtxt('sample_1.dat')
d2=np.genfromtxt('sample_2.dat')
d3=np.genfromtxt('sample_3.dat')
d4=np.genfromtxt('sample_4.dat')

x_axis = np.arange(-10, 10, 0.001)
plt.subplot(221)
plt.plot(x_axis, norm.pdf(x_axis,mu,sigma),label='sample 1')
plt.hist(d1,normed=1)
plt.legend()

plt.subplot(222)
plt.plot(x_axis, norm.pdf(x_axis,mu,sigma),label='sample 2')
plt.hist(d2,normed=1)
plt.legend()

plt.subplot(223)
plt.plot(x_axis, norm.pdf(x_axis,mu,sigma),label='sample 3')
plt.hist(d3,normed=1)
plt.legend()

plt.subplot(224)
plt.plot(x_axis, norm.pdf(x_axis,mu,sigma),label='sample 4')
plt.hist(d4,normed=1)
plt.legend()

plt.title('Sample vs Real')
plt.savefig('sample.pdf')
