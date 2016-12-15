package was;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;

public class WasProductParser {
	private WasProduct wasProduct;
	private String id;
	private String version;
	private String date;
	private String level;
	
	public void parse() {
		try {
			// Create a new DocumentBuilder instance
			DocumentBuilder documentBuilder = DocumentBuilderFactory.newInstance().newDocumentBuilder();
			
			// Process the XML file and obtain the Document object
			Document doc = documentBuilder.parse(new InputSource(new FileInputStream("src/was/WAS.product")));
			
			// Get product root node
			Element productNode = doc.getDocumentElement();
			
			// Get name attribute from product node
			String name = productNode.getAttributes().getNamedItem("name").getTextContent();
			
			// product children nodes iteration
			NodeList productChildNodes = productNode.getChildNodes();
			
			for (int i = 0; i < productChildNodes.getLength(); i++) {
				
				Node productChildNode = productChildNodes.item(i);
				
				if (productChildNode instanceof Element) {
					
					// Get child node name
					String productChildNodeName = productChildNode.getNodeName();
					
					if (productChildNodeName.equals("id")) {
						
						// Get text that id node contains
						id = productChildNode.getTextContent();
						
					} if (productChildNodeName.equals("version")) {
						
						// Get text that version node contains
						version = productChildNode.getTextContent();
						
					} if (productChildNodeName.equals("build-info")) {
						
						// Get text that version node contains
						date = productChildNode.getAttributes().getNamedItem("date").getTextContent();
						
						// Get text that version node contains
						level = productChildNode.getAttributes().getNamedItem("level").getTextContent();
					}
					
					wasProduct = new WasProduct(name, id, version, date, level);
				}
			}
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (SAXException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} catch (ParserConfigurationException e) {
			e.printStackTrace();
		}
	}
	
	public WasProduct getWasProduct() {
		return wasProduct;
	}
}
