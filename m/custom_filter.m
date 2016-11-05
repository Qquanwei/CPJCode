% 自定义滤波器的实现

function ans=custom_filter(img)
  custom_filter=[1,0,1;0,1,0;1,0,0];
  ans=imfilter(img,custom_filter/sum(custom_filter(:)));
end
