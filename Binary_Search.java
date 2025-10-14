 class BinarySearch {
    private static int binarySearch(int numArray[], int number_to_search_for) {
        int low = 0;
        int high = numArray.length - 1;

        while (low <= high){
            int middleIndex = (low + high) / 2;
            int middleIndexNumber = numArray[middleIndex];

            if (number_to_search_for == middleIndexNumber){
                return middleIndex;
            }
            if (number_to_search_for < middleIndexNumber){
                high = middleIndex - 1;
            }
            if (number_to_search_for > middleIndexNumber){
                low = middleIndex + 1;
            }
        }

        return -1;
  }
    public static void main(String args[]) {

        int[] arrayofnums = {2,3,6,8,9,13,20};

        System.out.println(binarySearch(arrayofnums, 13));
        // 5

    }

}
