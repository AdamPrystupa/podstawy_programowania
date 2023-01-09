#!/bin/bash
if [ $# -gt 1 ] #jeśli podane zostały nazwa pliku i numer strony
then
        pdftk $1.pdf cat $2 output $1_cut.pdf
        pdfcrop --margins '-50 -50 -50 -50' $1_cut.pdf $1_crop.pdf
        convert $1_crop.pdf $1.jpg
        rm $1_cut.pdf $1_crop.pdf
else
        echo 'Wywołanie skryptu dla pliku relacja.pdf: ./pdf.sh relacja 1';
fi
