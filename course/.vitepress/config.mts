import { defineConfig } from "vitepress";

import themeConfig from "./themeConfig";

// https://vitepress.dev/reference/site-config
export default defineConfig({
	lang: "zh-CN",
	title: "计算机 408 圣经",
	description: "一个讲解计算机 408 的网站",
	sitemap: {
		hostname: "https://408.nvimer.org/",
	},
	lastUpdated: true,
	themeConfig: themeConfig,
});
