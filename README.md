# bootstrap-gww
Bootstrap code for GWW model, which works on positivity matrix defined in **arXiv: 1612.08140**

Other papers which will help to understand this code is **arXiv: 2108.08757** and **arXiv: 2109.08033**

> Run using _" bash run\_script "_

Control size of positivity matrix by changing **N** in code, where N = K + 1, where K is highest power of operator in matrix

The positivity of matrix is checked by checking how eigenvalues are behaving with the help of _LAPACK_ 

> Run time of code for say 1 million data points is less than 10 seconds for K = 6

Any suggestions : Write to me navdeep.s.dhindsa@gmail.com 

**I am now trying to use this idea for different matrix models, if you have any more ideas around it, ping me at above email**

Result for Wilson loop and and higher windings: 

**W vs $\lambda$**

<img src="results//W1.png" width="600"> 

**$W_2$ vs $\lambda$**

<img src="results//W2.png" width="600">

**$W_3$ vs $\lambda$**

<img src="results//W3.png" width="600">

**$W_4$ vs $\lambda$**

<img src="results//W4.png" width="600">

> The white dots in the shaded region represent missing data.
