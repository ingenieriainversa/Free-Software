/*
 * Application Server Discovery v0.01
 * MyHandler.java
 * Copyleft - 2016  Javier Dominguez Gomez
 * Written by Javier Dominguez Gomez <jdg@member.fsf.org>
 * GnuPG Key: 6ECD1616
 * Madrid, Spain
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

package was;

import java.util.ArrayList;
import java.util.List;

import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

public class MyHandler extends DefaultHandler {

	// List to hold Jvm object
	private List<Jvm> jvmList = null;
	private Jvm jvm = null;

	// getter method for Jvm list
	public List<Jvm> getJvmList() {
		return jvmList;
	}

	boolean bDeployedApplications = false;

	@Override
    public void startElement(String uri, String localName, String qName, Attributes attributes)
            throws SAXException {

        if (qName.equalsIgnoreCase("serverEntries")) {
            //create a new Jvm and put it in Map
            String serverName = attributes.getValue("serverName");
            //initialize Jvm object and set id attribute
            jvm = new Jvm();
            jvm.setServerName(serverName);
            //initialize list
            if (jvmList == null)
            	jvmList = new ArrayList<Jvm>();
        } else if (qName.equalsIgnoreCase("deployedApplications")) {
            //set boolean values for fields, will be used in setting Jvm variables
        	bDeployedApplications = true;
        }
    }

	@Override
	public void endElement(String uri, String localName, String qName)
			throws SAXException {
		if (qName.equalsIgnoreCase("serverEntries")) {
			// add Jvm object to list
			jvmList.add(jvm);
		}
	}
}
