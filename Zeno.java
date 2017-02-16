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

            /*
            I consider this situation to move in "cycles"
            A new cycle starts whenever Achilles reaches la tortuga's last starting location
            (tortuga's base case starting location: 100 units)

            The first three lines (the prints) describe the conditions at start of cycle
            The next three lines (the expressions/redefinitions) show how things change during the cycle
            These changes are not explicitly shown (i.e., printed) until the start of the NEXT cycle
            (so we don't see the positions they are at when finally aPos >= tPos.
            Because the loop breaks before those end positions can print.)

            example, using starting case
            "at time 0 achilles is at position 0 and tortuga is at 100"
            Then achilles runs to position 100 from position 0
            (taking 5 seconds; this is calculated by timeToReach.)
            He is now at position 100
            (his new position is registered by the redefined aPos.)
            In those 5 seconds, the turtle has gained distance as well.
            (this is shown by the new tPos)
            So Achilles is now at 0+100=100, the tortoise is now at 100+50=150
            The time elapsed is now 0+5=5 seconds
            These are our starting points for the NEXT cycle (loop)
            Repeat cycle (loop) with new starting points.
            */

            System.out.println("At time: " + totalTime);
            System.out.println("    " + a + " is at position " + aPos);
            System.out.println("    " + t + " is at position " + tPos);

            double timeToReach = (tPos - aPos) / aSpeed;
            /* above line: 
            creates new double called Time to Reach, which represents
            The TIME it would take Achilles to cover
            the CURRENT distance between him and la tortuga
            (distance / rate = time) */

            // FOR THE NEXT LOOP (should it be needed)
            // our starting points will become:
            totalTime = totalTime + timeToReach;
            aPos = aPos + timeToReach * aSpeed; // timeToReach * aSpeed = tPos - aPos
            tPos = tPos + timeToReach * tSpeed;
        }
    }
}

//going by halves: half of half of half of half...
//proves that YES, of course, achilles catches the tortoise eventually.