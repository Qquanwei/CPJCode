% 均值滤波器

function img = simple_mean_filter(img)
  kernel = 3; %核函数大小

  assert(mod(kernel,2)==1);  
  kernelMatrix = ones(kernel,kernel);
  img = imfilter(img,kernelMatrix/sum(kernelMatrix(:)));
end
