package park.tt.com.parking.ui;

import android.util.Log;

import org.json.JSONException;
import org.json.JSONObject;

import park.tt.com.parking.Base64Util;

/**
 * Created by floyd on 15-7-28.
 */
public class TestImpl implements TestInterface {
    @Override
    public void callTest(String k) {

        try {
            JSONObject jsonObject = new JSONObject(k);
        } catch (JSONException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void initBean() {
        Log.e("sysso----", "initBean");
        Base64Util.decode("5Lit5paHMA==");
    }

    @Override
    public void destoryBean() {
        Log.e("sysso----", "destoryBean");
    }
}
