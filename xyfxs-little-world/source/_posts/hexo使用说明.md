---
title: hexo使用说明
date: 2026-05-28 16:15:59
tags: 使用说明
---
## 模板结构分析

你的博客是一个 Hexo 站点，主题是 `loststar`。主要结构可以分成三部分：

1. 根目录：站点配置和命令
2. source：文章和页面内容
3. loststar：主题模板和样式

---

## 1. 根目录文件

### _config.yml
这是 Hexo 的全局配置文件，包含：
- 站点标题 `title`
- 站点描述 `description`
- 作者 `author`
- 站点地址 `url`
- 文章生成规则 `permalink`
- 主题名 `theme: loststar`
- 分页、分类、标签等 Hexo 内部设置

你想修改博客基本信息，就改这里：
- `title`
- `subtitle`
- `description`
- `author`
- `url`

### package.json
这里是项目依赖和常用命令：
- `npm run server`：本地预览
- `npm run build`：生成静态文件
- `npm run clean`：清理 Hexo 缓存

---

## 2. 内容目录

### _posts
这里是你的文章内容。你现在已有：
- `hello-world.md`

Hexo 的文章文件通常是 Markdown，并且包含 Front-matter（头部元数据），例如：
```md
---
title: Hello World
date: 2026-05-28 00:00:00
tags:
- 示例
---
```

你要写新文章，直接在这里添加新的 `.md` 文件。

### scaffolds
这是 Hexo 新文章默认模板。一般你用 `hexo new post "标题"` 创建文章时，会按这个模板生成内容。

---

## 3. 主题目录：loststar

这是你的博客外观和交互逻辑的核心。

### _config.yml
这是主题配置文件，决定很多页面效果和主题功能，比如：
- 头像 `avatar`
- 背景图 `background`
- 加载图 `loading`
- 侧边卡片 `card`
- 菜单导航 `menu`
- 页脚 `footer`
- 代码高亮、数学、搜索、评论等开关

你要改“主题风格”、“导航菜单”、“侧边信息”等，基本都改这里。

### layout
这里是页面模板：

- layout.ejs：整体页面骨架，头部、主体、底部都在这里组合
- `index.ejs`：首页
- `post.ejs`：文章页
- `archives.ejs`：归档页
- `categories.ejs`、`tags.ejs`：分类和标签页
- `comment.ejs`：评论区
- `menu.ejs`、`footer.ejs`：菜单和页脚部分

如果你想修改页面结构、添加新的模块、改变页面布局，就要改这些 `.ejs` 文件。

### source
这个目录放的是主题的前端资源：
- `css/main.css`
- `js/main.js`
- `images/`
- `js/lib/` 中的脚本

修改主题样式、动画、交互效果时，通常在这里改。

---

## 4. public 文件夹说明

public 是 Hexo 生成出来的静态站点文件，不是你直接编辑的源文件。

- public 由 `npm run build` 或 `hexo generate` 生成
- 你平时改的是 source 和 themes，然后重新生成

---

## 5. 你该怎么修改

### 修改博客基本信息
编辑 _config.yml：
- `title`
- `author`
- `description`
- `url`

### 修改主题设置
编辑 _config.yml：
- 修改头像、背景图、菜单、版权、功能开关
- 关闭/开启搜索、评论、数学公式、星空效果等

### 修改页面样式或布局
编辑 `themes/loststar/layout/*.ejs` 和 main.css

### 写新文章
在 _posts 新建 `.md` 文件：
- `title`
- `date`
- `tags`
- 内容用 Markdown 写

### 预览网站
在根目录运行：
- `npm install`（如果你还没安装依赖）
- `npm run server`
然后打开浏览器看本地效果

---



---

**整体框架**
这是一个基于 Hexo 的静态博客，主题叫 loststar，暗色星空风格，用了 Vue.js 做前端交互。

---

**一、根目录关键文件**

`_config.yml` — 博客全局配置
- title、author、language 这些基础信息
- theme: loststar（指定使用哪个主题）
- deploy: 部署到 Github Pages
- 还有各种 Hexo 插件的开关

`package.json` — 依赖管理
- hexo 本体
- hexo-renderer-ejs（模板引擎）
- hexo-deployer-git（部署到 GitHub 用）

---

**二、主题配置：themes/loststar/_config.yml**

这是改博客外观的核心文件，控制的东西有：
- **menu** → 导航栏菜单项（首页、归档、分类、标签等）
- **avatar** / **background** → 头像、背景图路径
- **social** → 社交媒体链接（GitHub、Twitter 等）
- **friends** → 友情链接（友链页面显示）
- **highlight** → 代码高亮主题（用的 GitHub 风格）
- **search** → 搜索功能开关
- **crypto** → 文章加密功能（可以给某些文章设密码）
- **math** → 数学公式 LaTeX 渲染开关

---

**三、布局模板：themes/loststar/layout/**

这些 .ejs 文件就是页面的 HTML 骨架：

- **layout.ejs** — 页面总框架，把 head、导航栏、内容区、footer 组合在一起
- **index.ejs** — 首页排版，显示 hero 大图和文章卡片
- **post.ejs** — 单篇文章页，显示文章标题、正文、标签、评论
- **card.ejs** — 首页上的文章卡片组件（封面、标题、摘要）
- **archives.ejs** — 归档页面，按时间线展示所有文章，带搜索框
- **tags.ejs** — 标签页面，点击标签后显示该标签下的文章
- **categories.ejs** — 分类页面，跟标签页类似
- **footer.ejs** — 页脚内容

---

**四、脚本文件：themes/loststar/scripts/**

- **taxonomy-style-helper.js** — 给不同分类/标签分配不同的颜色样式
- **heading-color-injector.js** — 自动给文章标题注入颜色

---

**五、前端 JS：themes/loststar/source/js/lib/**

每个单独的功能模块：
- **home.js** — 首页特效（视差滚动、动画）
- **stars.js** — 星星背景动画（那个星空粒子效果）
- **search.js** — 文章搜索功能
- **crypto.js** — 文章加密解锁逻辑
- **highlight.js** — 代码语法高亮
- **math.js** — MathJax 数学公式渲染
- **preview.js** — 图片点击放大预览

**main.js** — Vue 应用入口，控制：
- 页面加载动画
- 菜单栏滚动时隐藏/显示
- Discord 风格的黑条剧透点击揭示

---

**六、CSS 样式：themes/loststar/source/css/main.css**

所有自定义样式全在这个文件里，将近 27000 字符，涵盖了页面布局、颜色、字体、动画、响应式设计等。

---

**七、资源图片**

- avatar.gif / avatar.jpg — 头像
- background.jpg / bg-main.jpg — 背景图
- loading.gif — 加载动画
- star-chubby.svg — 星星图标

---

**八、已有文章：source/_posts/**

已经放了几篇示例文章，包括 hello-world、hexo 使用说明、博客语法说明等。

---

**总结一下改博客你需要动的地方：**

| 想改什么 | 改哪个文件 |
|---|---|
| 站点名称、描述、语言 | `_config.yml` 顶部 |
| 导航菜单、头像、背景图、友链、社交链接 | `themes/loststar/_config.yml` |
| 页面结构布局 | `themes/loststar/layout/*.ejs` |
| 颜色、字体、间距等样式 | `themes/loststar/source/css/main.css` |
| 交互效果、动画 | `themes/loststar/source/js/lib/*.js` |
| 写新文章 | 在 `source/_posts/` 下新建 .md 文件 |