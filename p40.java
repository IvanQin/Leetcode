public class Solution {
    List<Integer> cans=new ArrayList();
    int[] cans;
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
     	   cans=candidates;
	   Array.sort(cans);
	   dfs(new ArrayList(),0,target);
    }
    public void dfs(List<Integer> sol,int from,int target){
	if (tmp==target){
		boolean exist=false;
		for (int j=0;j<res.length();j++){
		    List<Integer> temp=res.get(j);
		    if (temp.length()!=sol.length())
			continue;
		    for (int k=0;k<temp.length();k++)
			if (temp.get(k)!=sol.get(k))
			   break;
		    if (k==temp.length()){
			exist=true;
			break;
			}
	            }

	        if (!exist){
			List<Integer> list=new ArrayList<Integer>(sol);
			res.add(list);
		}
		return;
	}
	else for (int i=from;i<cans.length() && target-cans[i]>=0;i++){
		   sol.add(cans[i]);
		   dfs(sol,i+1,target-can[i]);
		   sol.remove(new Integer(cans[i]));
		}
	}
}
