class RecentCounter {
//timestamp t to our collection of requests.
// need to ignore/remove requests that are more than 
// 3,000ms older than t
//keeping requests -->range [t-3,000, t]
//Queues--> add requests and remove old ones 
private Queue<Integer>requests;

    public RecentCounter() {//empty queue counter initialized
    requests=new LinkedList<>();
        
    }
    
    public int ping(int t) {
        //new timestamp to the queue
        requests.offer(t);
        //check the head of quuee remove or keep as it is
        while(!requests.isEmpty()&& requests.peek()<t-3000){
            requests.poll();
        }
        //queue size=num of requests in the range [t-3000, t]
        return requests.size();

    
        
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */
