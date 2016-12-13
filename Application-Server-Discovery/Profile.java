/*
 * Application Server Discovery v0.01
 * Profile.java
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

public class Profile {
	
	private String isAReservationTicket;
	private String isDefault;
	private String name;
	private String path;
	private String template;
	
	/* Jvm class constructor:
	 * @isAReservationTicket: Profile isAReservationTicket.
	 * @isDefault: Profile isDefault.
	 * @name: Profile name.
	 * @path: Profile path.
	 * @template: Profile template.
	 */
	public Profile(String isAReservationTicket, String isDefault, String name, String path, String template) {
		setIsAReservationTicket(isAReservationTicket);
		setIsDefault(isDefault);
		setName(name);
		setPath(path);
		setTemplate(template);
	}

	public String getIsAReservationTicket() {
		return isAReservationTicket;
	}

	public void setIsAReservationTicket(String isAReservationTicket) {
		this.isAReservationTicket = isAReservationTicket;
	}

	public String getIsDefault() {
		return isDefault;
	}

	public void setIsDefault(String isDefault) {
		this.isDefault = isDefault;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getPath() {
		return path;
	}

	public void setPath(String path) {
		this.path = path;
	}

	public String getTemplate() {
		return template;
	}

	public void setTemplate(String template) {
		this.template = template;
	}
	
	public void printProfileData() {
		System.out.printf("%s;%s;%s;%s;%s\n", getIsAReservationTicket(), getIsDefault(), getName(), getPath(), getTemplate());
	}
}
