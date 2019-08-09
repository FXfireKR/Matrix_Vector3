# CALCULATE MATRIX / VECTOR CLASS

# 1. Matrix Class           //Based 4 By 4 Matrix

 - VOID Random()              //getRandom Matrix ( 0 ~ 10 )
 - VOID Print()               //Show Matrix Elements in Consol
 - MATRIX InverseMatrix()     //getInverse Matrix
 - MATRIX Transpose()         //getTranspose Matrix
 - FLOAT Determinant()        //getDeterminant About Matrix Elements (4by4 Base) 1/det(A)
 - FLOAT Cofactor(int, int)   //getCofactor About Parameters Value (4by4 Base)
 - FLOAT Minor(int, int)      //getMinor About Parameters Value (4by4 Base)
 - MATRIX Adjoint()           //getAdjoint About Elements Cofactor Matrix (4by4 Base)
 
 - operator +, -, *           //Each Operator Overriding Calculate Between Matrix
 - operator <<                //Print Matrix's All Elemts Without Any Other Sentense
 
 
 # 2. Vector Class          //Based 3D (x, y, z)
 
  - operator +        //getVector Between Vectors Sum Vector
  - operator -        //getVector Between Vectors Subtract Vector
  - operator ==       //getBoolean Between Vectors Completly Equal
  - operator !=       //getBoolean Between Vectors Completly not Equal
  - operator <<       //Print Vector's Elements X, Y, Z
  
  - friend FLOAT Dot(VECTOR&, VECTOR&)        //get DotProduct About Parameter's Vector
  - friend VECTOR Cross(VECTOR&, VECTOR&)     //get CrossProduct About Parameter's Vector
 
