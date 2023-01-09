#!/bin/bash
cd $1 
mkdir pom
#for i in  *.JPG;
#do
 #zmieniona=$(echo $i | tr -s 'JPG' 'jpg' | tr -s ' ' '_')
#copy=`cp  $1/$i $1/pom/$zmieniona`
#echo"$copy"   
#echo $zamieniona
#convert -resize $2 pom/$zmieniona
#done
for j in *.jpg;
do
 zmieniona1=$(echo $j | tr -s 'jpg' 'JPG' | tr -s ' ' '_')
 cp -pr $1/$j pom/$zmieniona1
#convert -resize $2 pom/$zmieniona1#
done

#for k in *.jpeg;
#do
 # zmieniona2=$(echo $k | tr -s 'jpeg' 'JPEG' | tr -s ' ' '_')
  #cp -pr $1/$k pom/$zmieniona2
  #convert -resize $2 pom/$zmieniona2
 # done
#tar -cfz archiwum_obrazy.tar.gz pom
rmdir pom
