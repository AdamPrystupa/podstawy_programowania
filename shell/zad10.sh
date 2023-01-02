#!/bin/bash
cd $1 
mkdir pom
for file in  *.[jJ][pP][eE][gG]
do
  zmieniona=$(echo ${file%.*}'.jpeg' | tr -s ' ' '_')
  cp  "$1$file" "$1pom/$zmieniona"   
  convert "$1pom/$zmieniona" -resize $2 "$1pom/$zmieniona"   
done

for file in  *.[pP][nN][gG]
do
  zmieniona=$(echo ${file%.*}'.png' | tr -s ' ' '_')
   cp  "$1$file" "$1pom/$zmieniona"   
  convert "$1pom/$zmieniona" -resize $2 "$1pom/$zmieniona"   
done
  tar -czf archiwum_obrazy.tar.gz pom
#rm -r pom