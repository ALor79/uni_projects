// File: ComparatorCombination.java
// A combination of two Comparators.

package huffmanCodes;

import java.util.Comparator;

/**
 * A combination of two Comparators.
 */
public class ComparatorCombination implements Comparator {

  /**
   * The primary Comparator.
   */
  private Comparator primary;

  /**
   * The secondary Comparator.
   */
  private Comparator secondary;

  /**
   * Returns a new ComparatorCombination.
   * @param c1  The primary Comparator.
   * @param c2  The secondary Comparator.
   */
  public ComparatorCombination(Comparator c1, Comparator c2) {
    primary = c1;
    secondary = c2;
  }

  /**
   * Compares the two given Objects.
   * @param obj1  The first object.
   * @param obj2  The second object.
   * @returns     The result of applying the primary Comparator to obj1 and
   *              obj2 if that result is nonzero, or the result of applying
   *              the secondary Comparator otherwise.
   * @throws      ClassCastException  If either the primary or secondary
   *                                  Comparator throws a ClassCastException.
   */
  public int compare(Object obj1, Object obj2) throws ClassCastException {
    int r = primary.compare(obj1, obj2);
    if (r == 0) r = secondary.compare(obj1, obj2);
    return r;
  }
}
