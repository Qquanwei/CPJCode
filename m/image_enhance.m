% 图像增强，也即图像锐化处理
% 锐化的操作为先使用拉氏变换找出像素变化率高的部位
function ans=image_enhance(img)
  lap=fspecial('laplacian',0.2);
  sobel = fspecial('sobel');
  img = img(:,:,1);

  normal=@(m) (m-min(m(:)))/max((m-min(m(:)))(:));
  
  sobelimg =normal(filter2(sobel,img));
  lapimg = normal(filter2(lap,img));
  
  copyimg = (double)(img) / (double)(max(img(:)));
  
  copyimg = normal(copyimg+lapimg);

  subplot(2,2,1);imshow(img);
  subplot(2,2,2);imshow(sobelimg);
  subplot(2,2,3);imshow(copyimg);
  subplot(2,2,4);imshow(lapimg);  

  ans=copyimg;
end
