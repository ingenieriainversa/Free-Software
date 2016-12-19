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

import was.Was;
import was.WasProductParser;
import was.WasProduct;
import was.Profile;
import was.ProfileRegistryParser;
import was.Jvm;
import was.ServerindexParser;

public class Main {
	private static GetOpt go;
	private static Was was;
	private static WasProductParser wasProduct;
	private static WasProduct wasProductData;
	private static ProfileRegistryParser profileRegistryXml;
	private static ArrayList<Profile> profiles;
	private static ServerindexParser serverindexXml;
	private static ArrayList<Jvm> jvms;
	private static String was_home;

	public static void main(String[] args) {
		go = new GetOpt(args, "hp:");
		go.optErr = true;
		int ch = -1;
		was_home = "";
		String usage = "Usage: -p \"/opt/IBM/WebSphere/AppServer\" | -h";
		
		if(args.length == 0) {
			System.out.println(usage);
            System.exit(0);
		} else {
			while ((ch = go.getopt()) != GetOpt.optEOF) {
				if ((char) ch == 'p') {
					was_home = go.optArgGet();
				} else if ((char) ch == 'h') {
					System.out.println(usage);
		            System.exit(0);
				} else {
					System.exit(1);
				}
			}
		}
		
		// New instance of WasProductParser class
		wasProduct = new WasProductParser();
		// Parse WAS.product file
		wasProduct.parse(was_home);
		// Get WAS product data
		wasProductData = wasProduct.getWasProduct();
		
		
		// New instance of ProfileRegistryParser class
		profileRegistryXml = new ProfileRegistryParser();
		// Parse profileRegistry.xml file
		profileRegistryXml.parse(was_home);
		// Get Profiles ArrayList
		profiles = profileRegistryXml.getProfiles();
		
		
		// New instance of Was class
		was = new Was(wasProductData, profiles);
		
		
		System.out.println("Product data:");
		// Print all product data
		was.printWasProductData();
		
		System.out.println("\nProfile list:");
		// Print a profile list
		was.printProfileList();
		
		
		/* For each profile you can get, set or print
		 * all data that you want about it.
		 */
		int profileIndex = 0;
		while(profileIndex < was.getProfiles().size()) {
			
			// Get the profile
			Profile profile = was.getProfiles().get(profileIndex);
			
			// New instance of ServerindexParser class
			serverindexXml = new ServerindexParser();
			
			// Get the serverindex.xml absolute path
			String serverindexFile = profile.getServerindex();
			
			// Parse serverindex.xml file
			serverindexXml.parse(serverindexFile);
			
			// Get Jvms ArrayList
			jvms = serverindexXml.getJvms();
			
			// For each profile set the jvm ArrayList
			profile.setJvms(jvms);
			
			// For example, print the jvm name list
			System.out.println("\n"+profile.getName()+" Jvm list:");
			profile.printJvmList();
			
			++profileIndex;
		}
	}
}
