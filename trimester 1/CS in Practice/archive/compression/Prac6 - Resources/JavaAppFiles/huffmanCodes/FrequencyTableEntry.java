// File: FrequencyTableEntry.java
// An entry in a frequency table.

package huffmanCodes;

import java.util.Comparator;

/**
 * An entry in a frequency table.  The entry contains a Character and an
 * associated int count and String encoding.  Four Comparators are provided
 * for comparisons based on the three fields.
 */
public class FrequencyTableEntry {

  /**
   * The Character.
   */
  private Character theCharacter;

  /**
   * The count.
   */
  private int theCount;

  /**
   * The encoding.
   */
  private String theEncoding;

  /**
   * Constructs a new FrequencyTableEntry containing the given information.
   */
  public FrequencyTableEntry(Character c, int n, String s) {
    theCharacter = c;
    theCount = n;
    theEncoding = s;
  }

  /**
   * Returns the Character.
   */
  public Character getCharacter() {
    return theCharacter;
  }

  /**
   * Returns the count.
   */
  public int getCount() {
    return theCount;
  }

  /**
   * Returns the encoding.
   */
  public String getEncoding() {
    return theEncoding;
  }

  /**
   * Returns a Comparator that makes comparisons based on the Character.
   * The Comparator returns a postive number iff the first Character is
   * greater than the second in the natural ordering.
   */
  public static Comparator getCharacterComparator() {
    return new CharacterComparator();
  }

  /**
   * Returns a Comparator that makes comparisons based on the count.
   * The Comparator returns a positive number iff the first count is greater
   * than the second count.
   */
  public static Comparator getCountComparator() {
    return new CountComparator();
  }

  /**
   * Returns a Comparator that makes comparisons based on the encoding.
   * The Comparator returns a positive number iff the first encoding is
   * greater than the second in the natural ordering.
   */
  public static Comparator getEncodingComparator() {
    return new EncodingComparator();
  }

  /**
   * Returns a Comparator that makes comparisons based on the length of the
   * encoding.  The Comparator returns a positive number iff the first
   * encoding is longer than the second.
   */
  public static Comparator getEncodingLengthComparator() {
    return new EncodingLengthComparator();
  }
}

/**
 * A Comparator that makes comparisons based on the Character in two
 * FrequencyTableEntries.
 */
class CharacterComparator implements Comparator {

  /**
   * Compares the given Objects.
   * @param obj1   The first Object.
   * @param obj2   The second Object.
   * @returns      If both Objects are FrequencyTableEntries:
   *               <ul>
   *               <li> A positive number if the Character in obj1 is
   *                    greater than the Character in obj2.
   *               <li> 0 if the Characters in obj1 and obj2 are equal.
   *               <li> A negative number if the Character in obj1 is
   *                    less than the Character in obj2.
   *               </ul>
   * @throws       ClassCastException  If obj1 and obj2 are not both
   *                                   FrequencyTableEntries.
   */
  public int compare(Object obj1, Object obj2) throws ClassCastException {
    return ((FrequencyTableEntry) obj1).getCharacter().charValue() -
      ((FrequencyTableEntry) obj2).getCharacter().charValue();
  }
}

/**
 * A Comparator that makes comparisons based on the count in two
 * FrequencyTableEntries.
 */
class CountComparator implements Comparator {

  /**
   * Compares the given Objects.
   * @param obj1   The first Object.
   * @param obj2   The second Object.
   * @returns      If both Objects are FrequencyTableEntries:
   *               <ul>
   *               <li> A positive number if the count in obj1 is
   *                    greater than the count in obj2.
   *               <li> 0 if the counts in obj1 and obj2 are equal.
   *               <li> A negative number if the count in obj1 is
   *                    less than the count in obj2.
   *               </ul>
   * @throws       ClassCastException  If obj1 and obj2 are not both
   *                                   FrequencyTableEntries.
   */
  public int compare(Object obj1, Object obj2) throws ClassCastException {
    return ((FrequencyTableEntry) obj1).getCount() -
      ((FrequencyTableEntry) obj2).getCount();
  }
}

/**
 * A Comparator that makes comparisons based on the encoding in two
 * FrequencyTableEntries.
 */
class EncodingComparator implements Comparator {

  /**
   * Compares the given Objects.
   * @param obj1   The first Object.
   * @param obj2   The second Object.
   * @returns      If both Objects are FrequencyTableEntries:
   *               <ul>
   *               <li> A positive number if the encoding in obj1 is
   *                    greater than the encoding in obj2.
   *               <li> 0 if the encodings in obj1 and obj2 are equal.
   *               <li> A negative number if the encoding in obj1 is
   *                    less than the encoding in obj2.
   *               </ul>
   * @throws       ClassCastException  If obj1 and obj2 are not both
   *                                   FrequencyTableEntries.
   */
  public int compare(Object obj1, Object obj2) throws ClassCastException {
    return ((FrequencyTableEntry) obj1).getEncoding()
      .compareTo(((FrequencyTableEntry) obj2).getEncoding());
  }
}

/**
 * A Comparator that makes comparisons based on the length of the encoding 
 * in two FrequencyTableEntries.
 */
class EncodingLengthComparator implements Comparator {

  /**
   * Compares the given Objects.
   * @param obj1   The first Object.
   * @param obj2   The second Object.
   * @returns      If both Objects are FrequencyTableEntries:
   *               <ul>
   *               <li> A positive number if the encoding in 
   *                    obj1 is shorter than the encoding in obj2.
   *               <li> 0 if the encodings in obj1 and obj2 are the same 
   *                    length.
   *               <li> A negative number if the encoding in 
   *                    obj1 is shorter than the encoding in obj2.
   *               </ul>
   * @throws       ClassCastException  If obj1 and obj2 are not both
   *                                   FrequencyTableEntries.
   */
  public int compare(Object obj1, Object obj2) throws ClassCastException {
    return ((FrequencyTableEntry) obj1).getEncoding().length() -
      ((FrequencyTableEntry) obj2).getEncoding().length();
  }
}

