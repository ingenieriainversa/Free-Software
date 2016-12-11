/*
 * Application Server Discovery v0.01
 * Main.java
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

package main;

import java.util.ArrayList;

import was.Jvm;
import was.ServerindexParser;

public class Main {
	
	private static ServerindexParser serverindexXml;
	private static ArrayList<Jvm> jvms;
	
	public static void main(String[] args) {
		
		// New instance of ServerindexParser class
		serverindexXml = new ServerindexParser();
		
		// Parse serverindex.xml file
		serverindexXml.parse("src/was/serverindex.xml");
		
		// Get Jvms ArrayList
		jvms = serverindexXml.getJvms();
		
		// Jvms array iteration
		int index = 0;
		while(index < jvms.size()) {
			Jvm jvm = jvms.get(index);
			
			// For each Jvm print data
			jvm.printAppsData();

			++index;
		}
	}
}
