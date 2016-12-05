/*
 * Application Server Discovery v0.01
 * Jvm.java
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

public class Jvm {
	private String serverName;
	private String deployedApplications;

	public String getServerName() {
		return serverName;
	}

	public void setServerName(String serverName) {
		this.serverName = serverName;
	}

	public String getDeployedApplications() {
		return deployedApplications;
	}

	public void setDeployedApplications(String deployedApplications) {
		this.deployedApplications = deployedApplications;
	}

	@Override
	public String toString() {
		return "Employee:: serverName=" + this.serverName + " deployedApplications=" + this.deployedApplications;
	}

}
