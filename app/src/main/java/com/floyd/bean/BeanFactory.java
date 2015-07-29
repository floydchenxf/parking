package com.floyd.bean;

import android.util.Log;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by floyd on 15-7-28.
 */
public class BeanFactory {

    private static final String TAG = "BeanFactory";

    private static final Map<String, Bean> beanCache = new HashMap<String, Bean>();

    private static BeanCustomer mBeanCustomer;

    public static synchronized void setCustomBean(BeanCustomer beanCustomer) {
        Log.i(TAG, "setCustomBean------" + beanCustomer);
        mBeanCustomer = beanCustomer;
    }

    public static synchronized void registerBean(String beanName, Bean bean) {
        Log.i(TAG, "registerBean with beanName:" + beanName);
        if (mBeanCustomer != null && mBeanCustomer.customBean(beanName, beanCache)) {
            return;
        }

        boolean beanExist = isRegister(beanName);
        if (beanExist) {
            Log.i(TAG, "registerBean exist bean" + beanName);
            unRegisterBean(beanName);
        }
        bean.initBean();
        beanCache.put(beanName, bean);
    }

    public static <T extends Bean> T getBean(String beanName) {
        Bean b = beanCache.get(beanName);
        printBeans();
        if (b == null) {
            return null;
        }
        return (T) b;
    }

    private static void printBeans() {
        for (Map.Entry<String, Bean> ent : beanCache.entrySet()) {
            Log.i(TAG, "exists bean with key:" + ent.getKey() + "-----value:" + ent.getValue());
        }

    }

    public static boolean isRegister(String beanName) {
        return beanCache.containsKey(beanName);
    }

    public static void unRegisterBean(String beanName) {
        Log.i(TAG, "unRegisterBean with beanName:" + beanName);
        Bean bean = beanCache.get(beanName);
        if (bean != null) {
            Log.i(TAG, "unRegisterBean destory beanName:" + beanName);
            bean.destoryBean();
            bean = null;
        }
        beanCache.remove(beanName);
    }
}
