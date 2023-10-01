import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;
import java.net.*;
import org.json.simple.*;
import org.json.simple.parser.*;

import java.io.BufferedInputStream;
import java.io.ByteArrayOutputStream;
import java.io.InputStream;
import java.io.IOException;

import com.google.gson.Gson;
import com.google.gson.JsonArray;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;

class Result {

    /*
     * Complete the 'getRelevantFoodOutlets' function below.
     *
     * URL for cut and paste
     * https://jsonmock.hackerrank.com/api/food_outlets?city=<city>&page=<pageNumber>
     *
     * The function is expected to return an array of strings.
     * 
     * The function accepts a city argument (String) and maxCost argument(Integer).
     */
    final static String API = "https://jsonmock.hackerrank.com/api/food_outlets?";
    
    
    public static String readInputStreamAsString(InputStream in) throws IOException {

        BufferedInputStream bis = new BufferedInputStream(in);
        ByteArrayOutputStream buf = new ByteArrayOutputStream();
        int result = bis.read();
        while(result != -1) {
        byte b = (byte)result;
        buf.write(b);
        result = bis.read();
        }
        return buf.toString();
    }
    
    private static JsonObject runAPI(String apiEndPoint)
    {
        JsonObject resultJSON = null;
        try{
            URL url = new URL(apiEndPoint);  
            HttpURLConnection connection = (HttpURLConnection)url.openConnection();
            connection.setRequestMethod("GET");  
            connection.addRequestProperty("Content-Type", "application/json"); 
            InputStream is = connection.getInputStream();
            String resultString = readInputStreamAsString(is);
            
            resultJSON = new Gson().fromJson(resultString, JsonObject.class);
        }
        catch(Exception ex)
        {
            System.out.print("An Exception occurred while running the API: " + apiEndPoint + "\nException" + ex);
        }
        return resultJSON;
    }
    
    public static List<String> getRelevantFoodOutlets(String city, int maxCost)
    {
        List<String> relevantCityList = new ArrayList();
        int page = 1;
        while(true)
        {
            JsonObject currPageResponse = runAPI(API + "city="+city +"&page="+page);
            
            JsonArray data = currPageResponse.getAsJsonArray("data");

            for (JsonElement currData : data) {
                if(currData.getAsJsonObject().get("estimated_cost").getAsInt() <= maxCost) {
                    String cityName = currData.getAsJsonObject().get("name").getAsString();
                    relevantCityList.add(cityName);
                }

            }
            
            if(currPageResponse.get("total_pages").getAsInt() == page)
            {
                break;
            }
            page++;
        }
        return relevantCityList;
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String city = bufferedReader.readLine();

        int maxCost = Integer.parseInt(bufferedReader.readLine().trim());
  
        List<String> result = Result.getRelevantFoodOutlets(city, maxCost);
        
        for (int i = 0; i < result.size(); i++) {
            bufferedWriter.write(result.get(i));

            if (i != result.size() - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
