package com.floyd.bean;

import android.util.Log;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by floyd on 15-7-29.
 */
public class ClassBeanCustomer extends DefaultBeanCustomer {

    private static final String TAG = "ClassBeanCustomer";

    private Map<String, Class<? extends Bean>> classes = new HashMap<String, Class<? extends Bean>>();

    public void registerBeanClass(String beanName, Class<? extends Bean> clazz) {
        classes.put(beanName, clazz);
    }

    @Override
    public Bean createBean(String beanName) {
        Bean bean = null;
        Class<? extends Bean> clazz = this.classes.get(beanName);
        if (clazz == null) {
            Log.i(TAG, "can not found clazz for:" + beanName);
            return bean;
        }

        boolean isInterface = clazz.isInterface();
        if (isInterface) {
            Log.i(TAG, "clazz:" + clazz + " is an interface, pls check!");
            return bean;
        }

        try {
            bean = clazz.newInstance();
        } catch (InstantiationException e) {
            Log.i(TAG, "clazz:" + clazz + " instance cause error:" + e.getMessage());
        } catch (IllegalAccessException e) {
            Log.i(TAG, "clazz:" + clazz + " instance cause error:" + e.getMessage());
        }
        return bean;
    }
}
