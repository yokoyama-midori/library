document.addEventListener('DOMContentLoaded', function () {
  // 現在のタイムスタンプを取得  
  const timestamp = new Date().getTime();

  // すべてのCSSリンクを取得  
  const cssLinks = document.querySelectorAll('link[rel="stylesheet"]');

  // すべてのJavaScriptスクリプトを取得  
  const jsScripts = document.querySelectorAll('script[src]');

  // CSSリンクにタイムスタンプを追加  
  cssLinks.forEach(function (link) {
    if (link.href) {
      link.href = addVersionParam(link.href, timestamp);
    }
  });

  // JavaScriptスクリプトにタイムスタンプを追加  
  jsScripts.forEach(function (script) {
    if (script.src) {
      script.src = addVersionParam(script.src, timestamp);
    }
  });

  // URLにバージョンパラメータを追加する関数  
  function addVersionParam(url, version) {
    // URLにすでにパラメータがあるかチェック  
    const separator = url.includes('?') ? '&' : '?';
    // バージョンパラメータを追加  
    return url + separator + 'v=' + version;
  }
});