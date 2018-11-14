import matplotlib
matplotlib.use("Agg")
import numpy as np
import matplotlib.pyplot as plt
import sys
n=float(sys.argv[1])
mu=float(sys.argv[2])
sigma=float(sys.argv[3])

from scipy.stats import norm


d1=np.genfromtxt('sample_1.dat')
d2=np.genfromtxt('sample_2.dat')
d3=np.genfromtxt('sample_3.dat')
d4=np.genfromtxt('sample_4.dat')

x_axis = np.arange(-10, 10, 0.001)
plt.subplot(221)
plt.plot(x_axis, norm.pdf(x_axis,mu,sigma))
plt.hist(d1,normed=1)

plt.subplot(222)
plt.plot(x_axis, norm.pdf(x_axis,mu,sigma))
plt.hist(d2,normed=1)

plt.subplot(223)
plt.plot(x_axis, norm.pdf(x_axis,mu,sigma))
plt.hist(d3,normed=1)

plt.subplot(224)
plt.plot(x_axis, norm.pdf(x_axis,mu,sigma))
plt.hist(d4,normed=1)

plt.title('Sample vs Real')
plt.savefig('sample.pdf')
