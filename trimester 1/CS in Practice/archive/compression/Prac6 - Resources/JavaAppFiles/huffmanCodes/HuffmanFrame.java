// File: HuffmanFrame.java
// A window for displaying a Huffman tree and codes.

package huffmanCodes;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.util.Arrays;
import javax.swing.Box;
import javax.swing.BoxLayout;
import java.util.Comparator;
import java.awt.Dimension;
import java.awt.Font;
import javax.swing.JCheckBoxMenuItem;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JScrollPane;
import java.io.*;
import java.text.*;
/**
 * A window for displaying a Huffman tree and codes.
 */
public class HuffmanFrame extends JFrame {

    /**
     * The content pane.
     */
    private Box content = new Box(BoxLayout.X_AXIS);

    /**
     * The scrolling frequency table.
     */
    private JScrollPane codePane;

    /**
     * The Huffman tree.
     */
    HuffmanTree theTree;
    /**
     *
     */
    HuffmanTree thePairTree;
    /**
     * The frequency table.
     */
    private FrequencyTableEntry[] frequencyTable;

    /**
     * The current font size.
     */
    private static int fontSize = 12;

    /**
     * The current font style.
     */
    private static int fontStyle = Font.PLAIN;

    /**
     *
     */
    private int grouping = 1;

    /**
     * The current font.
     */
    private Font theFont;

    /**
     * The Font size menu.
     */
    private JMenu sizeMenu = new JMenu("Size");

    /**
     * The "Bold" check box.
     */
    private JCheckBoxMenuItem boldBox;

    /**
     * The "Italic" check box.
     */
    private JCheckBoxMenuItem italicBox;

    /**
     * Constructs a new HuffmanFrame from the given frequency table and tree.
     * @param t      Drawing of the Huffman tree.
     * @param chars  The Characters in the character set.
     * @param codes  The Huffman code of each corresponding Character.
     */
    public HuffmanFrame(HuffmanTree singletree, HuffmanTree pairTree) {
	theTree = singletree;
	thePairTree = pairTree;
	JMenuBar mb = new JMenuBar();
	setJMenuBar(mb);

	// The "Sort by..." menu
	JMenu m = new JMenu("Sort by...");
	JMenuItem sortByChar = new JMenuItem("Character");
	sortByChar.addActionListener
	    (new SortListener(this, FrequencyTableEntry.getCharacterComparator()));
	m.add(sortByChar);
	JMenuItem sortByCode = new JMenuItem("Encoding");
	sortByCode.addActionListener
	    (new SortListener(this, FrequencyTableEntry.getEncodingComparator()));
	m.add(sortByCode);
	JMenuItem sortByCodeLength = new JMenuItem("Encoding Length");
	sortByCodeLength.addActionListener
	    (new SortListener(this, 
			      FrequencyTableEntry.getEncodingLengthComparator()));
	m.add(sortByCodeLength);
	JMenuItem sortByCount = new JMenuItem("Frequency");
	sortByCount.addActionListener
	    (new SortListener(this, 
			      new ReverseComparator
			      (FrequencyTableEntry.getCountComparator())));
	m.add(sortByCount);
	mb.add(m);

	// The "Grouping" menu
	JMenu gm = new JMenu("Grouping...");
	JMenuItem single = new JMenuItem("Single");
	single.addActionListener
	    (new GroupingListener(this, 1));
	gm.add(single);

	JMenuItem pair = new JMenuItem("Pair");
	pair.addActionListener
	    (new GroupingListener(this, 2));
	gm.add(pair);
	mb.add(gm);

	// The "Font" menu
	JMenu fm = new JMenu("Font");
	for (int i = 10; i < 25; i += 2) {
	    JMenuItem it = new JMenuItem(String.valueOf(i));
	    it.addActionListener(new FontSizeListener(this, i));
	    sizeMenu.add(it);
	}
	fm.add(sizeMenu);
	FontStyleListener fstl = new FontStyleListener(this);
	if ((fontStyle & Font.BOLD) == 0)
	    boldBox = new JCheckBoxMenuItem("Bold");
	else boldBox = new JCheckBoxMenuItem("Bold", true);
	boldBox.addActionListener(fstl);
	fm.add(boldBox);
	if ((fontStyle & Font.ITALIC) == 0)
	    italicBox = new JCheckBoxMenuItem("Italic");
	else italicBox = new JCheckBoxMenuItem("Italic", true);
	italicBox.addActionListener(fstl);
	fm.add(italicBox);
	mb.add(fm);    

	setContentPane(content);
	frequencyTable = theTree.getFrequencyTable();
	sortFrequencyTable(new ComparatorCombination
			   (new ReverseComparator
			    (FrequencyTableEntry.getCountComparator()), 
			    new ComparatorCombination
			    (FrequencyTableEntry.getEncodingLengthComparator(), 
			     FrequencyTableEntry.getEncodingComparator())));
	setFontSize(fontSize);
	setSize(500, 300);
    }

    public void setGrouping(int g)
    {
	grouping = g;
    }
    public void setFrequencyTable()
    {
	if (grouping==1)
	    frequencyTable = theTree.getFrequencyTable();
	else
	    frequencyTable = thePairTree.getFrequencyTable();
    }
    /**
     * Sets the font size.
     */
    public void setFontSize(int size) {
	fontSize = size;
	theFont = new Font("Monospaced", fontStyle, fontSize);
	updateContent();
    }

    /**
     * Sets the font style according to user selection.
     */
    public void setFontStyle() {
	int boldMask = boldBox.isSelected() ? Font.BOLD : 0;
	int italicMask = italicBox.isSelected() ? Font.ITALIC : 0;
	fontStyle = boldMask | italicMask;
	theFont = new Font("Monospaced", fontStyle, fontSize);
	updateContent();
    }

    /**
     * Draws the tree and frequency panel.
     */
    public void updateContent() {
	content.removeAll();
	if (grouping==1)
	    content.add(new JScrollPane(theTree.getDrawing(theFont)));
	else if (grouping==2)
	    {
		content.add(new JScrollPane(thePairTree.getDrawing(theFont)));
	    }
	updateFrequencyPanel();
    }    

    /**
     * Updates the frequency panel to reflect the current state of the frequency
     * table.
     */
    public void updateFrequencyPanel() {
	Box tableBox = new Box(BoxLayout.X_AXIS);
	Box charBox = new Box(BoxLayout.Y_AXIS);
	Box hexBox = new Box(BoxLayout.Y_AXIS);
	Box codeBox = new Box(BoxLayout.Y_AXIS);
	Box lengthBox = new Box(BoxLayout.Y_AXIS);
	Box countBox = new Box(BoxLayout.Y_AXIS);
	int msglen, totFreq;
	double compression;
	DecimalFormat df;

	JLabel lbl = new JLabel("Char ");
	lbl.setFont(theFont);
	charBox.add(lbl);
	Box b = new Box(BoxLayout.X_AXIS);
	b.add(Box.createHorizontalGlue());
	if (grouping==2)
	    lbl = new JLabel("    ASCII      ");
	else if (grouping==1)
	    lbl = new JLabel(" ASCII ");
	lbl.setFont(theFont);
	b.add(lbl);
	hexBox.add(b);
	lbl = new JLabel("Huffman  ");
	lbl.setFont(theFont);
	codeBox.add(lbl);
	b= new Box(BoxLayout.X_AXIS);
	b.add(Box.createHorizontalGlue());
	lbl = new JLabel("Length  ");
	lbl.setFont(theFont);
	b.add(lbl);
	lengthBox.add(b);
	b = new Box(BoxLayout.X_AXIS);
	b.add(Box.createHorizontalGlue());
	lbl = new JLabel("Freq  ");
	lbl.setFont(theFont);
	b.add(lbl);
	countBox.add(b);
    
	try{
	    FileWriter fstream = new FileWriter("out.csv");
	    BufferedWriter out = new BufferedWriter(fstream);

	    totFreq=0;
	    msglen=0;
	    compression=0.0;
	    for (int i = 0; i < frequencyTable.length; i++) {
		char[] eArray = new char[grouping];
		FrequencyTableEntry e = frequencyTable[i];
		int ecode = (int)e.getCharacter();

		if (grouping==2)
		    {
			int ecode1, ecode2;
			ecode1= (ecode%26);
			ecode2= (ecode/26);
			eArray[0] = (char)(ecode1 + (int)'a');
			eArray[1] = (char)(ecode2 + (int)'a');
		    } else
		    if (grouping==1)
			eArray[0] = (char)ecode;

		String echar = new String(eArray);


		lbl = new JLabel(echar + "  ");
		out.write(echar + ",");
		lbl.setFont(theFont);
		charBox.add(lbl);
		b = new Box(BoxLayout.X_AXIS);
		b.add(Box.createHorizontalGlue());

		
		String lblstr;
		df = new DecimalFormat("00000000");
		if (grouping==1)
		    {
			lblstr = df.format(Double.parseDouble(Integer.toString((int) (eArray[0]), 2)));
		    }
		    else
			{
			    String s1 = df.format(Double.parseDouble(Integer.toString((int) (eArray[0]),2)));
			    String s2 = df.format(Double.parseDouble(Integer.toString((int) (eArray[1]),2)));
			    lblstr = s1+s2;
			}
		lbl = new JLabel(lblstr);
		//		out.write(Integer.toString((int)(e.getCharacter().charValue()),2));
		lbl.setFont(theFont);
		b.add(lbl);
		hexBox.add(b);
		lbl = new JLabel("  " + e.getEncoding() + "  ");
		msglen+=(e.getEncoding().length()*e.getCount());
		out.write(e.getEncoding()+",");
		lbl.setFont(theFont);
		codeBox.add(lbl);
		b= new Box(BoxLayout.X_AXIS);
		b.add(Box.createHorizontalGlue());
		lbl = new JLabel(String.valueOf(e.getEncoding().length())+" ");
		out.write(e.getEncoding().length()+",");
		lbl.setFont(theFont);
		b.add(lbl);
		lengthBox.add(b);
		b = new Box(BoxLayout.X_AXIS);
		b.add(Box.createHorizontalGlue());
		lbl = new JLabel(String.valueOf(e.getCount()));
		totFreq+=e.getCount();
		out.write(String.valueOf(e.getCount()));
		out.write("\n");
		lbl.setFont(theFont);
		b.add(lbl);
		countBox.add(b);
	    }
	    out.close();
	    compression=1.0-(double)(msglen)/(totFreq*8*grouping);
	    b = new Box(BoxLayout.X_AXIS);
	    lbl = new JLabel("Compression ");
	    lbl.setFont(theFont);
	    b.add(lbl);
	    charBox.add(b);
	    b = new Box(BoxLayout.X_AXIS);
	    
	    df = new DecimalFormat("##.#");
	    lbl = new JLabel(df.format(compression*100)+"%");
	    lbl.setFont(theFont);
	    b.add(lbl);
	    hexBox.add(b);

	    charBox.add(Box.createGlue());
	    hexBox.add(Box.createGlue());
	    codeBox.add(Box.createGlue());
	    lengthBox.add(Box.createGlue());
	    countBox.add(Box.createGlue());
	    tableBox.add(Box.createHorizontalStrut(5));
	    tableBox.add(charBox);
	    tableBox.add(hexBox);
	    tableBox.add(codeBox);
	    tableBox.add(lengthBox);
	    tableBox.add(countBox);
	    tableBox.add(Box.createHorizontalStrut(5));
	    if (codePane != null) content.remove(codePane);
	    codePane =
		new JScrollPane(tableBox, JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,
				JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
	    Dimension size = codePane.getPreferredSize();
	    codePane.setMinimumSize(new Dimension(size.width, 0));
	    codePane.setMaximumSize(new Dimension(size.width, 0x7fffffff));
	    content.add(codePane);
	    validate();
	    repaint();
	} catch(IOException e)
	    {
		e.printStackTrace();
	    }
    }

    /**
     * Sorts the frequency table using the given Comparator.
     */
    public void sortFrequencyTable(Comparator c) {
	Arrays.sort(frequencyTable, c);
    }
}

/**
 * Event handler for sort actions.
 */
class GroupingListener implements ActionListener {
    /**
     * The parent Frame.
     */
    private HuffmanFrame theFrame;
    /**
     * The grouping.
     */
    private int grouping;

    /**
     * Constructs a new GroupingListener 
     */
    public GroupingListener(HuffmanFrame f, int g) {
	theFrame = f;
	grouping = g;
    }
    /**
     * Handles the event.  The parameter is ignored.
     */
    public void actionPerformed(ActionEvent e) {
	theFrame.setGrouping(grouping);
	theFrame.setFrequencyTable();
	theFrame.updateContent();
    }
}




/**
 * Event handler for sort actions.
 */
class SortListener implements ActionListener {

    /**
     * The parent Frame.
     */
    private HuffmanFrame theFrame;

    /**
     * The Comparator.
     */
    private Comparator theComparator;

    /**
     * Constructs a new SortListener that will sort using the given Comparator.
     */
    public SortListener(HuffmanFrame f, Comparator c) {
	theFrame = f;
	theComparator = c;
    }

    /**
     * Handles the event.  The parameter is ignored.
     */
    public void actionPerformed(ActionEvent e) {
	theFrame.sortFrequencyTable(theComparator);
	theFrame.updateFrequencyPanel();
    }
}

/**
 * Handles font size change events.
 */
class FontSizeListener implements ActionListener {

    /**
     * The parent frame.
     */
    private HuffmanFrame parent;

    /**
     * The size.
     */
    private int size;

    /**
     * Constructs a new FontSizeListener that handles changes to the given 
     * size. 
     */
    public FontSizeListener(HuffmanFrame f, int i) {
	parent = f;
	size = i;
    }

    /**
     * Handles the event.  The parameter is ignored.
     */
    public void actionPerformed(ActionEvent e) {
	parent.setFontSize(size);
    }
}

/**
 * Handles font style change events.
 */
class FontStyleListener implements ActionListener {

    /**
     * The parent frame.
     */
    private HuffmanFrame parent;

    /**
     * Constructs a new FontSizeListener. 
     */
    public FontStyleListener(HuffmanFrame f) {
	parent = f;
    }

    /**
     * Handles the event.  The parameter is ignored.
     */
    public void actionPerformed(ActionEvent e) {
	parent.setFontStyle();
    }
}
