import matplotlib.pyplot as plt
x1=[4,8,16,32,64,128,256,512,1024,2048,4096,8192]
x2=[4,8,16,32,64,128,256,512,1024,2048,4096,8192]
x3=[4,8,16,32,64,128,256,512,1024,2048,4096,8192]

y1=[1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000, 1.000000, 1.000000]
y2=[0.607537,1.264074,1.515979,1.413981,1.935214,2.443775,2.769266,2.536814,2.741529,2.983705,3.330177,3.312186]
y3=[0.946134,3.520136,5.606564,6.702280,7.952000,8.896952,7.464730,6.435969,6.498083,6.371759,6.474328,6.472033]

plt.ylim(1, 10)
plt.xlim(0, 8192)
# plt.scatter(x1, y1)
# plt.scatter(x2, y2)
# plt.scatter(x3, y3)
plt.plot(x1,y1,label='serial bitonic sort',)
plt.plot(x2,y2,label='std sort')
plt.plot(x3,y3,label='simd bitonic sort')
plt.xlabel('array size')
plt.ylabel('(time of sort)/(time of serial bitonic sort)')
plt.title('performance')
plt.legend()
plt.show()