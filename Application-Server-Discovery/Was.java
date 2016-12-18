/*
 * Application Server Discovery v0.01
 * Was.java
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

public class Was {
	private WasProduct wasProduct;
	private ArrayList<Profile> profiles;
	private ArrayList<Jvm> jvms;
	
	/* Was class constructor:
	 * @wasProduct: WAS product data.
	 * @profiles: WAS profiles ArrayList.
	 * @jvms: WAS Jvms ArrayList.
	 */
	public Was(WasProduct wasProduct, ArrayList<Profile> profiles, ArrayList<Jvm> jvms) {
		setWasproduct(wasProduct);
		setProfiles(profiles);
		setJvms(jvms);
	}

	public WasProduct getWasProduct() {
		return wasProduct;
	}

	public void setWasproduct(WasProduct wasProduct) {
		this.wasProduct = wasProduct;
	}

	public ArrayList<Profile> getProfiles() {
		return profiles;
	}

	public void setProfiles(ArrayList<Profile> profiles) {
		this.profiles = profiles;
	}

	public ArrayList<Jvm> getJvms() {
		return jvms;
	}

	public void setJvms(ArrayList<Jvm> jvms) {
		this.jvms = jvms;
	}
	
	public void printWasProductData() {
		// Print Was product data
		wasProduct.printWasData();
	}
	
	public void printProfileList() {
		// Profiles array iteration
		int index = 0;
		while (index < profiles.size()) {
			Profile profile = profiles.get(index);

			// For each Profile print data
			System.out.println(profile.getName());

			++index;
		}
	}
	
	public void printJvmList(String endPointName) {
		// Jvms array iteration
		int index = 0;
		while (index < jvms.size()) {
			Jvm jvm = jvms.get(index);

			// For each Jvm print data
			jvm.printEndPointsData(endPointName);
			// jvm.printAppsData();

			++index;
		}
	}
}

