import java.io.IOException;
import org.apache.commons.httpclient.HttpClient;
import org.apache.commons.httpclient.HttpException;
import org.apache.commons.httpclient.methods.GetMethod;
import org.apache.commons.httpclient.methods.PostMethod;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonObject;

/**
 * This class shows an example of obtaining an OAuth2 token using the LPS /token API, and then validating that token using the LPS /validate API.
 * 
 * This class depends on two open source projects, the maven pom entries are:
 * 
 *
 * <pre>
 * {@code
 <!-- this is an example set of dependencies from within a maven pom.xml configuration -->
 	<dependency>
		<groupId>commons-httpclient</groupId>
		<artifactId>commons-httpclient</artifactId>
		<version>3.1</version>
	</dependency>
	<dependency>
		<groupId>com.google.code.gson</groupId>
		<artifactId>gson</artifactId>
		<version>2.8.0</version>
	</dependency>
}
 * </pre>
 * 
 */
public class Oauth2Example
{
	public static void main(String[] args) throws HttpException, IOException
	{
		if (args.length != 4)
		{
			System.out.println("args should be <url> <username> <password> <community>");
			return;
		}

		String host = args[0];
		String username = args[1];
		String password = args[2];
		String community = args[3];

		Oauth2Example example = new Oauth2Example();

		String token = example.getToken(host, username, password, community);
		System.out.println("token is: " + token);

		boolean valid = example.validate(host, token);
		System.out.println("token is valid: " + valid);

		valid = example.validate(host, "an_invalid_token");
		System.out.println("invalid token is valid: " + valid);
	}

	public String getToken(String host, String username, String password, String community) throws HttpException, IOException
	{
		PostMethod tokenMethod = new PostMethod(host + "/ls/api/oauth2/token");
		tokenMethod.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
		tokenMethod.addParameter("grant_type", "password");
		tokenMethod.addParameter("username", username);
		tokenMethod.addParameter("password", password);
		tokenMethod.addParameter("scope", "community=" + community);

		HttpClient httpClient = new HttpClient();
		httpClient.executeMethod(tokenMethod);

		int status = tokenMethod.getStatusCode();

		if (status == 200)
		{
			String responseJsonString = tokenMethod.getResponseBodyAsString();
			JsonObject responseJson = new GsonBuilder().create().fromJson(responseJsonString, JsonObject.class);
			String token = responseJson.get("access_token").getAsString();
			return token;
		}
		else
		{
			/* some error occurred, examine the response status message and response body */
			return null;
		}

	}

	private boolean validate(String host, String token) throws HttpException, IOException
	{
		GetMethod validateMethod = new GetMethod(host + "/ls/api/oauth2/validate");
		validateMethod.setRequestHeader("Authorization", "Bearer " + token);
		HttpClient httpClient = new HttpClient();
		httpClient.executeMethod(validateMethod);

		int status = validateMethod.getStatusCode();

		return status == 200;
	}

}
