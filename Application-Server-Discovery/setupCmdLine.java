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
