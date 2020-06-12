// File: ReverseComparator.java
// The reverse of a given Comparator.

package huffmanCodes;

import java.util.Comparator;

/**
 * The reverse of a given Comparator.
 */
public class ReverseComparator implements Comparator {

  /**
   * The original Comparator.
   */
  private Comparator originalComparator;

  /**
   * Returns a new ReverseComparator.
   */
  public ReverseComparator(Comparator c) {
    originalComparator = c;
  }

  /**
   * Compares the two given Objects.
   * @param obj1  The first object.
   * @param obj2  The second object.
   * @returns     The negative of the result of applying the original
   *              Comparator to obj1 and obj2.
   * @throws      ClassCastException  If the original
   *                                  Comparator throws a ClassCastException.
   */
  public int compare(Object obj1, Object obj2) throws ClassCastException {
    return -originalComparator.compare(obj1, obj2);
  }
}
