import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long n = Long.parseLong(br.readLine());

        long mid = (n+1)/2;
        System.out.println("? " + mid);
        System.out.flush();
        String eggPlant = br.readLine();

        long left = mid, right = mid;
		long s = 1, e = mid, m = 0;
		String res;
		while(s<=e) {
			m = (s+e)/2;
			System.out.println("? "+m);
			System.out.flush();
			res = br.readLine();
			if(eggPlant.equals(res)) {
				left = m;
				e = m-1;
			}
			else {
				s = m+1;
			}
			
		}
		
		s = mid;
		e = n;
		while(s<=e) {
			m = (s+e)/2;
			System.out.println("? "+m);
			System.out.flush();
			res = br.readLine();
			if(eggPlant.equals(res)) {
				right = m;
				s = m+1;
			}
			else {
				e = m-1;
			}
			
		}
	
		System.out.println("! "+left+" "+right);
		System.out.flush();
        
    }
}