/*
 * Application Server Discovery v0.01
 * SetupCmdLine.java
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

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;

public class setupCmdLine {
	
	public Properties getCell(String was_home) throws IOException {

		Properties prop = new Properties();
		InputStream inputStream = this.getClass().getClassLoader().getResourceAsStream("was/setupCmdLine.sh");

		if (inputStream == null) {
			throw new FileNotFoundException("property file '" + was_home + "' not found in the classpath");
		}

		prop.load(inputStream);
		
		String cell = prop.getProperty("WAS_CELL");
		
		System.out.println("\nCell: "+cell);

		return prop;
	}
}
