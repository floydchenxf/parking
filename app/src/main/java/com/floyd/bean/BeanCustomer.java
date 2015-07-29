package com.floyd.bean;

import java.util.Map;

/**
 * Created by floyd on 15-7-29.
 */
public interface BeanCustomer {

    /**
     * 是否定制bean
     *
     * @param beanName
     * @param beanCache
     * @return
     */
    boolean customBean(String beanName, Map<String, Bean> beanCache);
}
