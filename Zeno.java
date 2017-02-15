public class Zeno {
    public static void main(String[] args) {
        String a = "Achilles";
        String t = "Tortoise";
        double aPos = 0;   // Achilles starts at 0
        double tPos = 100; // tortoise has a 100-unit head start
        double aSpeed = 20;
        double tSpeed = 10;
        /*
        this is not the same as Dad's "will-he-ever-catch-up" problem
        because the algebra clearly shows that Achilles will reach the tortoise
        (do 100 + 10x = 20x)
        CHANGED MY MIND, ACTUALLY IT IS
         */
        double totalTime = 0; // start at time 0

        while (aPos < tPos) { 

            // NOTE: This loop increments by time remaining
            // not by any set time interval (e.g. every 2 seconds)

            System.out.println("At time: " + totalTime);
            System.out.println("    " + a + " is at position " + aPos);
            System.out.println("    " + t + " is at position " + tPos);

            double timeToReach = (tPos - aPos) / aSpeed;
            /* above line: 
            creates new double called Time to Reach, which represents
            The time it would take Achilles to cover
            the distance that remains at this time
            between him and la tortuga */

            // FOR THE NEXT ITERATION OF THE LOOP 
            totalTime = totalTime + timeToReach;
            // increments up totalTime by adding TO the CURRENT total time (time elapsed)
            // the time remaining until Achilles reaches the tortoise at their speeds
            aPos = aPos + timeToReach * aSpeed;
            // Achilles's position increments up by 
            // adding TO his CURRENT position
            // the distance he covers in the remaining time (instantaneous)
            // that it will take him to reach the tortoise 
            tPos = tPos + timeToReach * tSpeed;
            // Tortoise's position increments up by 
            // adding TO his CURRENT position
            // the distance he covers in the remaining time (instantaneous)
            // that it will take Achilles to reach him 
        }
    }
}