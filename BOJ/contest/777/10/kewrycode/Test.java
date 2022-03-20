import java.util.ArrayList;

public class Test {
	static ArrayList<Long> calc(ArrayList<Long> v, int N)
	{
		ArrayList<Long> ans = new ArrayList<Long>(N);
		ans.add(1L);
		
		for (int x = 1; x < N; x++) {
			ans.add(0L);
			for (int y = 0; y < x; y++) {
				long m = 1000000000000000000L;
				for (int z = y; z <= x; z++) {
					m = Math.min(m, v.get(z));
				}
				
				ans.set(x, ans.get(x) + ans.get(y) * m);
				ans.set(x, ans.get(x) % 1000000007);
			}
		}
		return ans;
	}
}
