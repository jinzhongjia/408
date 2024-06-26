import { defineConfig } from "vitepress";

import themeConfig from "./themeConfig";

// https://vitepress.dev/reference/site-config
export default defineConfig({
  lang: "zh-CN",
  title: "计算机 408 学习笔记",
  description: "一个讲解计算机 408 的网站",
  sitemap: {
    hostname: "https://408.nvimer.org/",
  },
  lastUpdated: true,
  themeConfig: themeConfig,
  markdown: {
    math: true,
    image: {
      lazyLoading: true,
    },
  },
  cleanUrls: true,
});
