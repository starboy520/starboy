import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

// Give a set of integer
// input all the subset of this array
public class Subset {
	public static List< List<Integer> > getSubset(List<Integer> set) {
		int size = set.size();
		int max = 1 << size;
		List<List<Integer>> allsubsets = new ArrayList<List<Integer>>();
		for (int i = 0; i < max; i++) {
			List<Integer> oneset = new ArrayList<Integer>();
			int k = i;
			int index = 0;
			while ( k > 0) {
				if ((k & 1) > 0) {
					oneset.add(set.get(index));
				}
				index++;
				k >>= 1;
			}
			allsubsets.add(oneset);
		}
		return allsubsets;
	}
	
	public static List< List<Integer> > getSubset(List<Integer> set, int index) {
		List< List<Integer> > allsubset = new ArrayList<List<Integer>>();
		if (index == set.size()) {
			allsubset.add(new ArrayList<Integer>());
		} else {
			List< List<Integer> > currentSubset = getSubset(set, index+1);
			int item = set.get(index);
			ArrayList<ArrayList<Integer>> moresubsets = new ArrayList<ArrayList<Integer>>();
			for (List<Integer> oneset : currentSubset) {
				List<Integer> thisset = new ArrayList<Integer>();
				int num = set.get(index);
				thisset.addAll(oneset);
				thisset.add(num);
				moresubsets.add(thisset);
			}
			allsubset.addAll(moresubsets);
		}
		
		return allsubset;
	}
	
	public static void main(String[] args) {
		List<Integer> a = Arrays.asList(1,2,3);
		System.out.println(getSubset(a));
		//System.out.println(getSubset(a, 0));
	}
}
