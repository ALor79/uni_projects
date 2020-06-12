// File: Driver.java
// A demo to display Huffman codes and trees.

package huffmanCodes;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.Button;
import java.awt.Container;
import java.io.File;
import javax.jnlp.FileContents;
import javax.swing.filechooser.FileFilter;
import javax.jnlp.FileOpenService;
import java.io.FileReader;
import java.awt.FlowLayout;
import java.io.InputStreamReader;
import java.io.IOException;
import javax.swing.JApplet;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.jnlp.ServiceManager;
import javax.swing.UIManager;
import javax.jnlp.UnavailableServiceException;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

/**
 * A demo to display Huffman codes and trees.
 */
public class Driver extends JApplet {

  /**
   * The text field in which the input strings will be entered.
   */
  JTextField text = new JTextField(15);

  /** Constructs a new Driver applet.
   */
  public Driver() {
    try {
      UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
    }
   catch (Exception e) {
      // This shouldn't happen
      e.printStackTrace();
    }
    Container content = getContentPane();
    content.setLayout(new FlowLayout());
    content.add(new JLabel("Enter String: "));
    text.addActionListener(new TextEntryListener(this));
    content.add(text);
    Button btn = new Button("Choose File");
    btn.addActionListener(new FileOpenListener(this));
    content.add(btn);
  }

  /**
   * Starts the program as an application.
   */
  public static void main(String[] args) {
    JFrame f = new JFrame();
    f.setContentPane(new Driver());
    f.addWindowListener(new Terminator());
    f.setTitle("Huffman Codes");
    f.pack();
    f.show();
  }

  /**
   * Returns the input string provided by the user.
   */
  public String getInputString() {
    String s = text.getText();
    text.setText("");
    return s;
  }
}

/**
 * The event handler for the text field.
 */
class TextEntryListener implements ActionListener {

  /**
   * The driver applet.
   */
  private Driver theDriver;

  /**
   * Constructs a new TextEntryListener.
   */
  public TextEntryListener(Driver d) {
    theDriver = d;
  }

    private boolean validLetter(int c) 
    {

	char ch = (char)c;

	if (ch>='a' && ch<='z')
	    return true;
	if (ch>='A' && ch<='Z')
	    return true;
	return false;
    }



  /**
   * Handles the event.
   */
  public void actionPerformed(ActionEvent e) {
    String s = theDriver.getInputString();
    char[] sArray;
    char [] oArray = new char[s.length()];
    int grouping=2;
    int ostringlen=0;
    HuffmanTree singleTree, pairTree;

    sArray = s.toCharArray();

    int j=0;
    for (int i=0;i<sArray.length;i++)
	{
	    char ch=sArray[i];
	    int c = (int)ch;
	    if ((ch>='a' && ch<='z')||(ch>='A' && ch<='Z'))
		{
		    if (c < (int)'a')
			c = c - (int)'A' + (int)'a';
		    oArray[j++]=(char)c;

		}
	}
    ostringlen=j;
    String os = new String(oArray);
    os = os.substring(0,ostringlen);
    singleTree=new HuffmanTree(os);

    int[] pair = new int[2];
    int pairfound;
    j=0;

    pairfound=0;
    for (int i=0;i<sArray.length;i++)
	{
	    char ch= sArray[i];
	    int c =(int)ch;
	    
	    if ((ch>='a' && ch<='z')||(ch>='A' && ch<='Z'))
		{
		    if (c < (int)'a')
			c = c - (int)'A' + (int)'a';
		    pair[pairfound++]=(char)(c-(int)'a');
		}
	    if (pairfound==2)
		{
		    pairfound=0;
		    oArray[j++] = (char)(pair[0]+26*pair[1]);
		}
	}
    ostringlen=j;
    String osp = new String(oArray);
    osp = osp.substring(0,ostringlen);
    pairTree = new HuffmanTree(osp);

    HuffmanFrame f = new HuffmanFrame(singleTree, pairTree);
    f.setTitle("Huffman Tree");
    f.show();
  }
}

/**
 * The event handler for closing the driver frame.
 */
class Terminator extends WindowAdapter {

  /**
   * Handles the event by terminating the program.
   */
  public void windowClosing(WindowEvent e) {
    System.exit(0);
  }
}

/**
 * The event handler for opening a file.
 */
class FileOpenListener implements ActionListener {

  /**
   * The driver.
   */
  private Driver theDriver;

  /**
   * Constructs a new FileOpenListener.
   */
  public FileOpenListener(Driver d) {
    theDriver = d;
  }

  /**
   * Handles the event.  The parameter is ignored.
   */
  public void actionPerformed(ActionEvent e) {
    InputStreamReader in;
    try {
      try { // First try to go through WebStart
	in = WebStartHelper.getInputStreamReader();
      }
      catch (NoClassDefFoundError er) { // javax.jnlp is not found
	in = getInputStreamReader();    // Use a JFileChooser instead
      }
      catch (UnsupportedOperationException er) { // FileOpenService unavailable
	in = getInputStreamReader();
      }
      /*      if (in != null) { // If a file was selected
	StringBuffer sb = new StringBuffer();
	int c = in.read();
	while (c != -1) {
	  sb.append((char) c);
	  c = in.read();
	}
	HuffmanFrame f = new HuffmanFrame(new HuffmanTree(sb.toString()));
	f.setTitle("Huffman Tree");
	f.show();
	}*/
    }
    catch (IOException ex) { 
      JOptionPane.showMessageDialog(theDriver, ex.getMessage(), 
				    "I/O Error", JOptionPane.WARNING_MESSAGE);
    }
    catch (SecurityException ex) {
      JOptionPane.showMessageDialog(theDriver,
				    "Access to the file system is prohibited.",
				    "Security Error",
				    JOptionPane.WARNING_MESSAGE);
    }
    catch (NoClassDefFoundError ex) {
      JOptionPane.showMessageDialog(theDriver,
				    "Package EDU.ksu.cis.viewer not found.",
				    "Load Error", JOptionPane.WARNING_MESSAGE);
    }
  }

  /**
   * Gets an InputStreamReader associated with a file chosen by the user.
   * This method uses a JFileChooser to obtain the file.  If no file is
   * chosen, the method returns null.
   * @throws SecurityException  If read access to the file or file system is
   *                            denied.
   * @throws IOException        If the file cannot be opened.
   */
  private InputStreamReader getInputStreamReader() 
    throws SecurityException, IOException {
    JFileChooser fc = new JFileChooser();
    fc.addChoosableFileFilter(new TextFileFilter());
    int ret = fc.showOpenDialog(theDriver);
    if (ret == JFileChooser.APPROVE_OPTION) {
      File inFile = fc.getSelectedFile();
      return new FileReader(inFile);
    }
    else return null;
  }
}

/**
 * This class contains a single static method used to obtain an
 * InputStreamReader associated with a file while operating under
 * Java WebStart.  This method is loaded as a separate class because it
 * contains references to the package javax.jnlp, which might not be
 * avaialable at run time.  By including the method in a separate class,
 * we have control over when it is loaded, and how to handle the
 * NoClassDefFoundError if it occurs.
 */
class WebStartHelper {

  /**
   * Returns an InputStream reading from a file selected by the user.
   * @throws UnsupportedOperationException  If the ServiceManager does not
   *                                        support a FileOpenService.
   * @throws IOException If an error occurs in reading the file system or
   *                     opening the file.
   */
  public static InputStreamReader getInputStreamReader() 
    throws UnsupportedOperationException, IOException {
    try {
      FileOpenService fos = 
	(FileOpenService) 
	ServiceManager.lookup("javax.jnlp.FileOpenService");
      FileContents fc = fos.openFileDialog(null, new String[] {"txt"}); 
      if (fc != null)
	return new InputStreamReader(fc.getInputStream());
      else return null;
    }
    catch (UnavailableServiceException e) {
      throw new UnsupportedOperationException("FileOpenService unavailable.");
    }
  }
}

/**
 * FileFilter for text files.
 */
class TextFileFilter extends FileFilter {

  /**
   * Returns whether the given file is accepted by this filter.
   */
  public boolean accept(File f) {
    String name = f.getName();
    return f.isDirectory() || 
      (name.length() >= 4 && name.substring(name.length()-4).equals(".txt"));
  }

  /**
   * The description of this filter.
   */
  public String getDescription() {
    return "Text Files (*.txt)";
  }
}
