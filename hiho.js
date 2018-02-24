/******************************************************************************
 **                Copyright (C) 2018, fuliucansheng. All Rights Reserved
 **
 **  FileName:   hiho.js
 **  Desc:       generate readme
 **  Author:     fuliucansheng
 **  Email:      fuliucansheng@gmail.com
 **  LastChange: 2018-02-24 21:49:56
 **  History:    2018-02-24 Create by fuliucansheng
 ******************************************************************************/

var fs = require("fs")
var http = require("http")
var async = require("async")
var cheerio = require("cheerio")
var eventproxy = require("eventproxy")

var uid = 76193
var host = "www.hihocoder.com"

var get_problem = function() {
  var options = {
    hostname: host,
    port: 80,
    path: "/user/" + uid + "/problemset",
    method: 'GET'
  }
  var domstr = ""
  var req = http.request(options, function(res) {
    res.setEncoding('utf8');
    res.on("data", function(r) {
      domstr += r;
    })
    res.on("end", function() {
      var problems = []
      var $ = cheerio.load(domstr);
      $("article").map(function(idx, problem) {
        var plink = $(problem).find("h4 > a").attr("href");
        var pid = $(problem).find("h4").text().split("：")[0].substr(1).trim();
        var pname = $(problem).find("h4").text().split("：")[1].trim();
        problems.push({
          "id": parseInt(pid),
          "href": plink,
          "name": pname
        })
      });
      problems.sort(function(a, b) {
        return a.id - b.id;
      })
      ep.emit("problems", problems)
    })
  })

  req.on('error', function(e) {
    console.log('problem with request: ' + e.message);
  });

  return req.end();
}

var get_userinfo = function() {
  var options = {
    hostname: host,
    port: 80,
    path: "/user/" + uid,
    method: 'GET'
  }
  var domstr = "";
  var req = http.request(options, function(res) {
    res.setEncoding('utf8');
    res.on("data", function(r) {
      domstr += r;
    })
    res.on("end", function() {
      var userinfo = {};
      var $ = cheerio.load(domstr);
      var username = $(".profile-header-summary > .name").text().trim();
      userinfo["name"] = username;
      var dstr = $(".content-section-body").html();
      dstr = dstr.replace("<!--", "");
      dstr = dstr.replace("-->", "");
      $ = cheerio.load(dstr)
      var dict = {
        "通过题目数": "pass",
        "总提交数": "submit",
        "参加hiho一下次数": "hiho",
        "参加挑战赛次数": "contest"
      }
      $("ul.hiho-statistical li").map(function(idx, li) {
        var k = $(li).text().split("：")[0].trim();
        var v = $(li).text().split("：")[1].trim();
        userinfo[dict[k]] = v;
      })
      ep.emit("userinfo", userinfo)
    })
  })

  req.on('error', function(e) {
    console.log('problem with request: ' + e.message);
  });

  return req.end();
}

var gen_readme = function(problems, userinfo) {
  var gen_title = function() {
    return "\n# HihoCoder\n";
  }

  var gen_userinfo = function() {
    var name = "##### " + userinfo.name;
    var pass = "AC: " + userinfo.pass;
    var submit = "Submit: " + userinfo.submit;
    var hiho = "Hiho: " + userinfo.hiho;
    var contest = "Contest: " + userinfo.contest;
    return [name, pass, submit, hiho, contest].join("&nbsp;|&nbsp;") + "\n"
  }

  var gen_feature = function() {
    var title = "\n### Features\n";
    var feats = ["Written with C/C++ (use C++11/C++14)", "Perferred STL (Standard Template Library)", "Non-ACM style programming"];
    var featstr = "";
    feats.forEach(function(feat) {
      featstr += "* " + feat + "\n";
    })
    return [title, featstr].join("\n")
  }

  var gen_hiho = function() {
    var title = "\n### Code";
    var code = "```bash\nnpm install\n### 修改hiho.js中的uid\nnode hiho.js # 即可生成readme.md\n```";
    return [title, code].join("\n") + "\n"
  }

  var gen_solution = function() {
    var title = "\n### Solutions\n";
    var head = "| # | Problem | Solution |";
    var split = "|:-:|:-------:|:--------:|";
    var body = "";
    problems.forEach(function(problem, idx) {
      var pn = "[" + problem.name + "](http://" + host + problem.href + ")";
      var ps = "[" + problem.id + "](./solutions/" + problem.id + ".cpp)";
      body += "|" + [idx + 1, pn, ps].join("|") + "|\n"
    })
    return [title, head, split, body].join("\n")
  }

  var mstr = [gen_title(), gen_userinfo(), gen_feature(), gen_hiho(), gen_solution()].join("");
  fs.writeFile("./readme.md", mstr, function(err) {
    if (err) {
      return console.log("generation failed!");
    }
    return console.log("generation success!");
  })
}

async.parallel([get_problem, get_userinfo])

var ep = new eventproxy();
ep.all("problems", "userinfo", gen_readme)
