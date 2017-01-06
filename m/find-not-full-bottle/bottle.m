 src = imread('1.jpg');
imshow(src)
src_bw=im2bw(src,0.85);
figure;imshow(src_bw)
w=fspecial('average',[5 5]);
src_aver=imfilter(src_bw,w);
figure;imshow(src_aver,[])
img1=src_aver(:,1:498/5);
img2=src_aver(:,498/5:498*2/5);
img3=src_aver(:,498*2/5:498*3/5);
img4=src_aver(:,498*3/5:498*4/5);
img5=src_aver(:,498*4/5:498*5/5);
sum1=sum(img1(:))
sum2=sum(img2(:))
sum3=sum(img3(:))
sum4=sum(img4(:))
sum5=sum(img5(:))
if(sum1>=3000)
   figure; text(0.3,0.5,'不合格的瓶子是1')
   axis off;
end
if(sum2>=3000)
   figure; text(0.3,0.5,'不合格的瓶子是2')
   axis off;
end

if(sum3>=3000)
   figure; text(0.3,0.5,'不合格的瓶子是3')
   axis off;
end

if(sum4>=3000)
   figure; text(0.3,0.5,'不合格的瓶子是4')
   axis off;
end
if(sum5>=3000)
   figure; text(0.3,0.5,'不合格的瓶子是5')
   axis off;
end


if(sum1>=3000)
   figure; text(0.3,0.5,'不合格的瓶子是1')
   axis off;
end

