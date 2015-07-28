using System;

class Hello {
	public static long P(long n) {
		return (1 - n + (long)Math.Pow (n, 2.0) - (long)Math.Pow (n, 3.0) + (long)Math.Pow (n, 4.0) - (long)Math.Pow (n, 5.0) + (long)Math.Pow (n, 6.0) - (long)Math.Pow (n, 7.0) + (long)Math.Pow (n, 8.0) - (long)Math.Pow (n, 9.0) + (long)Math.Pow (n, 10.0));
	}
	
	public static long P1(long n) {
		return (long)Math.Pow(n,3);
	}
	
	public static void Main() {
		int[] y = {1, 8, 27};
		System.Console.WriteLine("Hello p101!");
		long total = 0;
		for (int n = 1; n <= 10; n++) {
			long result = 0;
			for (long i = 1; i <= n; i++) {
				long temp1 = 1;
				long temp2 = 1;
				for (long j = 1; j <= n; j++) {
					if (i == j) {
						continue;
					} else {
						temp1 *= n + 1 - j;
						temp2 *= i - j;
					}
				} 
				result += temp1 * P(i)/temp2;
			}
			System.Console.WriteLine(result);
			total += result;
		}
		System.Console.WriteLine(total);
		for (int i=1; i<=10; i++) {
			System.Console.Write(P(i)  + " ");
		}
		System.Console.WriteLine();
	}
}
