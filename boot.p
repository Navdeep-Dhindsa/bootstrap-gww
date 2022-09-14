set terminal postscript eps enhanced color font "arial,18"
set output 'K.eps'

set key spacing 1.5
set border lw 1.5

set xtics 0.0,0.5,3.0
set ytics 0.0,0.25,1.0

set xrange [0:3.0]
set yrange [0.0:1.0]

set xlabel "{/Symbol l}" 
set ylabel "W"

plot "final.txt" using 1:2 pt 16 ps 0.1 lw 0.1 lc rgb "#ff0000" title "K=6"
