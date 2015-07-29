package com.floyd.bean;

import java.util.Map;

/**
 * Created by floyd on 15-7-29.
 */
public abstract class DefaultBeanCustomer implements BeanCustomer {

    @Override
    public boolean customBean(String beanName, Map<String, Bean> beanCache) {
        Bean bean = createBean(beanName);
        if (bean == null) {
            return false;
        }

        bean.initBean();
        beanCache.put(beanName, bean);
        return true;
    }

    public abstract Bean createBean(String beanName);
}
