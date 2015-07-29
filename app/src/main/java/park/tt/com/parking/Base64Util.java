package park.tt.com.parking;

import android.text.TextUtils;
import android.util.Base64;
import android.util.Log;

/**
 * Created by floyd on 15-7-22.
 */
public class Base64Util {

	private static final String TAG = "Base64Util";

	public static String encode(String key) {
		return encode(key, "UTF-8");
	}

	public static String encode(String key, String encode) {
		if (TextUtils.isEmpty(key)) {
			return null;
		}

		byte[] bytes = null;
		try {
			bytes = key.getBytes(encode);
		} catch (Exception e) {
			bytes = key.getBytes();
		}
		byte[] encodeBytes = Base64.encode(bytes, Base64.DEFAULT);
		String enc = new String(encodeBytes);
		Log.i(TAG, "String:" + key + "-----encoded string:" + enc);
		return enc.replaceAll("[\r|\n]", "");
	}

	public static String decode(String encodeStr) {
		byte[] result = Base64.decode(encodeStr, Base64.DEFAULT);
		String res = new String(result);
		Log.i(TAG, "String:" + encodeStr + "-----decoded string:" + res);
		return res;
	}

	public static String fetchEncodeAccount(String mPrefix, String account) {
		String result = null;
		if (mPrefix != null && mPrefix.startsWith("u")) {
			result = Base64Util.encode(account);
		} else {
			result = account;
		}

		return result;
	}

	public static String fetchDecodeAccount(String mPrefix, String account) {
		String result = null;
		if (mPrefix != null && mPrefix.startsWith("u")) {
			result = Base64Util.decode(account);
			Log.i("Base64Util", "-----userId:"+result);
		} else {
			result = account;
		}

		return result;
	}

	public static String fetchDecodeAccount(String lid) {
		String result = null;
		if (TextUtils.isEmpty(lid)) {
			return result;
		}

		String prefix = lid.substring(0, 8);
		String account = lid.substring(8);
		return fetchDecodeAccount(prefix, account);
	}
}
