import { DefaultTheme } from "vitepress";

export default [
  {
    text: "什么是 408 ？",
    link: "/",
  },

  {
    text: "数据结构",
    items: [
      {
        text: "绪论",
        link: "/DataStructure/introduction",
      },
      {
        text: "线性表",
        items: [
          {
            text: "定义",
            link: "/DataStructure/linearList/definition",
          },
        ],
      },
    ],
  },
  {
    text: "计算机组成原理",
    items: [],
  },
  {
    text: "计算机网络",
    items: [],
  },
  {
    text: "操作系统",
    items: [],
  },
] as DefaultTheme.Sidebar;
