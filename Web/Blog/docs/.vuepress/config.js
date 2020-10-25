module.exports = {
    title: 'Aliex',
    description: '个人小站',

    themeConfig:{
        nav:[
            {text:'主页',link:'/'},
            {text:'个人学习',link:'/Vue.html'},
            {text:'谷歌搜索',link:'https://google.com'},
            {   //二级列表
                text:'分类',
                items:[
                    {
                        text:'前端',
                        items:[
                            {text:'HTML',link:'/html/'},
                            {text:'Vue',link: 'vue'}
                        ],
                    },
                    {
                        text:'后端',
                        items:[
                            {text:'C',link:'/c/'},
                            {text:'Java',link: '/Java/'},
                        ]
                    }
                ]
            },
            {   //下拉列表
                text:'语言',
                items:[
                    {text:'中文',link:'/language/chinese'},
                    {text:'英语',link:'/language/english'}
                ]
            }

        ],

        // sidebar:'auto',
        // sidebar:[
        //     {
        //         title: '这是标题',
        //         children:
        //             ['/', ['/Vue', 'Vue标题'], '/home1']
        // }
        // ],
        sidebar:{
            '/bar/':['','one','two'],
            '/page-a/':['',['a','A'],'b'],
            '/':['','home1','Vue']
        },
        sidebarDepth:2
    },


}


