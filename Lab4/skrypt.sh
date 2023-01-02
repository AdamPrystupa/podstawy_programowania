#!/bin/bash

# Pobierz ścieżki do plików z katalogu
find "$1" -type f -name "*.jpg" -o -name "*.png" |

# Zmienia rozszerzenia plików na małe litery
xargs -I{} bash -c 'mv "{}" "$(basename "{}" .JPG)".jpg'

# Zmienia spacje w nazwach plików na znaki podkreślenia
for file in "$1"/*.jpg; do
  mv "$file" "${file// /_}"
done

# Skopiuje pliki o wskazanym rozmiarze i jakości
width=$2
height=$3
quality=$4
for file in "$1"/*.jpg; do
  convert "$file" -resize "${width}x${height}" -quality "$quality" "${file}.tmp"
  mv "${file}.tmp" "$file"
done

# Tworzy archiwum z przygotowanych plików
tar -czvf "$1/photos.tar.gz" "$1"
