// A Hello World! program in C#. 
using System;
using System.Numerics;
namespace HelloWorld
{
    class Hello 
    {
    
	private static BigInteger Squareroot(int n, int digits) {
		BigInteger limit = BigInteger.Pow(10, digits + 1);
		BigInteger a = 5 * n;
		BigInteger b = 5;

		while (b < limit) {
			if (a >= b) {
			    a -= b;
			    b += 10;
			} else {
			    a *= 100;
			    b = (b/10) * 100 + 5;
			}
		}
		return b/100;
	}
	
	private static int DigitSum(BigInteger number) {
		char[] k = number.ToString().ToCharArray();
		int ds = 0;
		for(int i = 0; i < k.Length; i++){
		ds += Convert.ToInt32(k[i].ToString());
		}
		return ds;
	}
	
        static void Main() 
        {
		int result = 0;
		int j = 1;
		 
		for (int i = 1; i <= 100; i++) {
			if (j * j == i) {
				j++;
				continue;
			}
			result += DigitSum(Squareroot(i, 100));
		}
        }
    }
}