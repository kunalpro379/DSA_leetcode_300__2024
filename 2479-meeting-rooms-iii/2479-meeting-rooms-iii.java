class Solution {
    public int mostBooked(int n, int[][] meetings) {
        Arrays.sort(meetings,(a,b)->Integer.compare(a[0], b[0]));
        //count of meetings in each room
        int[] roomMeets=new int[n];
        //minheap for avilbale name
        PriorityQueue<Integer>freeRooms=new PriorityQueue<>();
        for(int i=0;i<n;i++)freeRooms.offer(i);

PriorityQueue<long[]> busyRooms = new PriorityQueue<>((a, b) -> {
    if (a[0] != b[0]) return Long.compare(a[0], b[0]); // sort by end time
    return Integer.compare((int)a[1], (int)b[1]); // tie-break by room number
});


        for(int[] meeting: meetings){
            long start=meeting[0], end=meeting[1];
            long duration=end-start;
            //free rooms that finiished before the current time
            while(!busyRooms.isEmpty()&&busyRooms.peek()[0]<=start){
                freeRooms.offer((int)busyRooms.poll()[1]);
            }
            if(!freeRooms.isEmpty()){
                //assign to free room
                int room=freeRooms.poll();
                roomMeets[room]++;
                busyRooms.offer(new long[]{end,room});
            }else{
                ///delay the meeting
                long[] earliest=busyRooms.poll();
                long newStart=earliest[0];
                int room=(int) earliest[1];
                roomMeets[room]++;
                busyRooms.offer(new long[]{newStart+duration, room});
            }
        }        int maxRoom = 0;
        for (int i = 1; i < n; i++) {
            if (roomMeets[i] > roomMeets[maxRoom]) {
                maxRoom = i;
            }
        }

        return maxRoom;
    }
}