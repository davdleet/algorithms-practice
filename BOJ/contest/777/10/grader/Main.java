import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

public class Main {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int N = Integer.parseInt(br.readLine());
		String[] word = br.readLine().split(" ");
		ArrayList<Long> v = new ArrayList<Long>(N); 
		for(int i = 0; i < N; i++)
			v.add(Long.parseLong(word[i]));
		br.close();
		
		ArrayList<Long> ans = Test.calc(v, N);
		for(Long x : ans)
			bw.write(x+"\n");
		bw.flush();
		bw.close();
	}

}
